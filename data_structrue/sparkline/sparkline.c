#include "sparkline.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

static char charset[] = "_-`";
static char charset_fill[] = "_o#";
static int charset_len = sizeof(charset)-1;
static int label_margin_top = 1;

struct sequence *createSparklineSequence(void) {
    struct sequence *seq = malloc(sizeof(*seq));
    seq->length = 0;
    seq->samples = NULL;
    return seq;
}

void sparklineSequenceAddSample(struct sequence *seq, double value, char *label) {
    label = (label == NULL || label[0] == '\0') ? NULL : strdup(label);
    if (seq->length == 0) {
        seq->min = seq->max = value;
    } else {
        if (value < seq->min) seq->min = value;
        else if (value > seq->max) seq->max = value;
    }
    seq->samples = realloc(seq->samples,sizeof(struct sample)*(seq->length+1));
    seq->samples[seq->length].value = value;
    seq->samples[seq->length].label = label;
    seq->length++;
    if (label) seq->labels++;
}

void freeSparklineSequence(struct sequence *seq) {
    int j;

    for (j = 0; j < seq->length; j++)
        free(seq->samples[j].label);
    free(seq->samples);
    free(seq);
}

sds sparklineRenderRange(sds output, struct sequence *seq, int rows, int offset, int len, int flags) {
    int j;
    double relmax = seq->max - seq->min;
    int steps = charset_len*rows;
    int row = 0;
    char *chars = malloc(len);
    int loop = 1;
    int opt_fill = flags & SPARKLINE_FILL;
    int opt_log = flags & SPARKLINE_LOG_SCALE;

    if (opt_log) {
        relmax = log(relmax+1);
    } else if (relmax == 0) {
        relmax = 1;
    }

    while(loop) {
        loop = 0;
        memset(chars,' ',len);
        for (j = 0; j < len; j++) {
            struct sample *s = &seq->samples[j+offset];
            double relval = s->value - seq->min;
            int step;

            if (opt_log) relval = log(relval+1);
            step = (int) (relval*steps)/relmax;
            if (step < 0) step = 0;
            if (step >= steps) step = steps-1;

            if (row < rows) {
                /* Print the character needed to create the sparkline */
                int charidx = step-((rows-row-1)*charset_len);
                loop = 1;
                if (charidx >= 0 && charidx < charset_len) {
                    chars[j] = opt_fill ? charset_fill[charidx] :
                                          charset[charidx];
                } else if(opt_fill && charidx >= charset_len) {
                    chars[j] = '|';
                }
            } else {
                /* Labels spacing */
                if (seq->labels && row-rows < label_margin_top) {
                    loop = 1;
                    break;
                }
                /* Print the label if needed. */
                if (s->label) {
                    int label_len = strlen(s->label);
                    int label_char = row - rows - label_margin_top;

                    if (label_len > label_char) {
                        loop = 1;
                        chars[j] = s->label[label_char];
                    }
                }
            }
        }
        if (loop) {
            row++;
            output = sdscatlen(output,chars,len);
            output = sdscatlen(output,"\n",1);
        }
    }
    free(chars);
    return output;
}

sds sparklineRender(sds output, struct sequence *seq, int columns, int rows, int flags) {
    int j;

    for (j = 0; j < seq->length; j += columns) {
        int sublen = (seq->length-j) < columns ? (seq->length-j) : columns;

        if (j != 0) output = sdscatlen(output,"\n",1);
        output = sparklineRenderRange(output, seq, rows, j, sublen, flags);
    }
    return output;
}

struct sequence *argument_to_sequence(const char *arg) {
    struct sequence *seq = create_sequence();
    char *copy, *start;

    start = copy = strdup(arg);
    while(*start) {
        char *label, *end, *endptr;
        double value;

        end = strchr(start,',');
        if (end) *end = '\0';
        label = strchr(start,':');
        if (label) {
            *label = '\0';
            label++; /* skip the ':' */
        }
        errno = 0;
        value = strtod(start,&endptr);
        if (*endptr != '\0' || errno != 0 || isinf(value) || isnan(value)) {
            errno = EINVAL;
            return NULL;
        }
        sequence_add_sample(seq,value,label ? strdup(label) : NULL);
        if (end)
            start = end+1;
        else
            break;
    }
    free(copy);
    return seq;
}


void parse_args(int argc, char **argv) {
    int j;

    for (j = 1; j < argc; j++) {
        int lastarg = (j == argc-1);
        if (!strcasecmp(argv[j],"--help")) {
            show_help();
        } else if (!strcasecmp(argv[j],"--binfreq")) {
            opt_mode = ASPARK_MODE_BINFREQ;
        } else if (!strcasecmp(argv[j],"--txtfreq")) {
            opt_mode = ASPARK_MODE_TXTFREQ;
        } else if (!strcasecmp(argv[j],"--stream")) {
            opt_mode = ASPARK_MODE_STREAM;
        } else if (!strcasecmp(argv[j],"--log")) {
            opt_log = 1;
        } else if (!strcasecmp(argv[j],"--fill")) {
            opt_fill = 1;
        } else if (!strcasecmp(argv[j],"--columns") && !lastarg) {
            opt_columns = atoi(argv[++j]);
        } else if (!strcasecmp(argv[j],"--rows") && !lastarg) {
            opt_rows = atoi(argv[++j]);
        } else if (!strcasecmp(argv[j],"--label-margin-top") && !lastarg) {
            opt_label_margin_top = atoi(argv[++j]);
        } else {
            if (opt_data == NULL) {
                opt_data = argv[j];
            } else {
                fprintf(stderr,"Unrecognized option: '%s'\n", argv[j]);
                exit(1);
            }
        }
    }
    if (opt_mode != ASPARK_MODE_ARGUMENT && opt_data) {
        fprintf(stderr,"Error: data argument passed but incompatible mode selected.\n");
        exit(1);
    } else if (opt_mode == ASPARK_MODE_ARGUMENT && !opt_data) {
        fprintf(stderr,"Error: missing data.\n");
        exit(1);
    }
}
