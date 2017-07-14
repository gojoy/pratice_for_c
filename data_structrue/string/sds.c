#include "sds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int sdsll2str(char *s, long long value) {
    char *p, aux;
    unsigned long long v;
    size_t l;

    /* Generate the string representation, this method produces
     * an reversed string. */
    v = (value < 0) ? -value : value;
    p = s;
    do {
        *p++ = '0'+(v%10);
        v /= 10;
    } while(v);
    if (value < 0) *p++ = '-';

    /* Compute length and add null term. */
    l = p-s;
    *p = '\0';

    /* Reverse the string. */
    p--;
    while(s < p) {
        aux = *s;
        *s = *p;
        *p = aux;
        s++;
        p--;
    }
    return l;
}

sds sdsnewlen(const void *init, size_t initlen) {
	struct sdshdr32 *sh;
	sds s;
	int hdrlen=sizeof(struct sdshdr32);
	sh=(struct sdshdr32 *)malloc(hdrlen+initlen+1);
	if(sh==NULL) {
		fprintf(stderr,"malloc error\n");
		return NULL;
	}
	if(!init)
		memset(sh,0,hdrlen+initlen+1);
	s=(char *)sh+hdrlen;
	//SDS_HDR_VART(32,s);
	sh->len=initlen;
	sh->alloc=initlen;
	sh->flags=1;
	if(init&&initlen)
		memcpy(s,init,initlen);
	s[initlen]='\0';
	return s;
}

sds newsds(const char *init) {
	size_t initlen;
	if(init==NULL)
		initlen=0;
	else
		initlen=strlen(init);
	return sdsnewlen(init,initlen);
}

sds sdsempty() {
	return sdsnewlen("",0);
}

sds sdsdup(sds s) {
	return sdsnewlen(s,sdslen(s));
}

void sdsfree(sds s) {
	if(s==NULL) return;
	SDS_HDR_VART(32,s);
	free(sh);
}

void showsds(sds s) {
	printf("s is %s,len is %d,alloc is %d\n",s,sdslen(s),sdsalloc(s));
}


sds sdsgrowzero(sds s,size_t len) {
	int curlen=sdslen(s);
	if(curlen>=len)
		return s;
	s=sdsMakeRoomfor(s,(len-curlen));
	if(s==NULL){
		fprintf(stderr,"grow false\n");
		return NULL;
	}
	memset(s+len,0,(len-curlen+1));
	sdssetlen(s,len);
	return s;
}




sds sdsMakeRoomfor(sds s,size_t addlen){
	void *sh,*newsh;
	size_t len,newlen;
	int avail=sdsavible(s);
	if(avail>=addlen)
		return s;
	len=sdslen(s);
	sh=(char *)(s)-sdshdrsize(s);
	newlen=len+addlen;

	if(newlen<SDS_MAX_PREALLOC)
		newlen*=2;
	else
		newlen+=SDS_MAX_PREALLOC;

	sh=realloc(sh,sdshdrsize(s)+newlen+1);
	if(sh==NULL){
		fprintf(stderr,"makeroom false\n");
		return NULL;
	}
	sdssetalloc(s,newlen);
	return s;
}

sds sdscpylen(sds s, const char *init, size_t len) {
	if(sdsalloc(s)<len)
		s=sdsMakeRoomfor(s,len-sdslen(s));
	if(s==NULL) {
		fprintf(stderr,"cpy false\n");
		return NULL;
	}
	memcpy(s,init,len);
	s[len]='\0';
	sdssetlen(s,len);
	return s;
	

}

sds sdscpy(sds s, const char *t) {
	return sdscpylen(s,t,strlen(t));
}



sds sdscatlen(sds s, const void *init ,size_t len) {
	int curlen=sdslen(s);
	s=sdsMakeRoomfor(s,len);
	if(s==NULL) {
		fprintf(stderr,"catlen error\n");
		return NULL;
	}
	memcpy(s+curlen,init,len);
	sdssetlen(s,curlen+len);
	s[curlen+len]='\0';
	return s;

}

sds sdscat(sds s, const char *init) {
	return sdscatlen(s,init,strlen(init));

}

sds sdscatsds(sds s, const sds t) {
	return sdscatlen(s,t,sdslen(t));

}

sds sdsfmt(sds s, char *fmt,...) {
	va_list ap;
	int i,len=sdslen(s);
	const char *f;
	va_start(ap,fmt);
	f=fmt;
	i=len;	// postiom

	while(*f) {
		char next,*str;
		int num,l;
		if(sdsavible(s)==0)
			s=sdsMakeRoomfor(s,1);
		switch(*f) {
			case '%':
				next=*(f+1);
				f++;
				switch(next) {
					case 'i':
					case 'I':
						num=va_arg(ap,int);

						char buf[SDS_LLSTR_SIZE];
						memset(buf,0,SDS_LLSTR_SIZE);

						l=sdsll2str(buf,num);
						if(l>sdsavible(s))
							s=sdsMakeRoomfor(s,l);
						memcpy(s+i,buf,l);
						i+=l;
						sdsinclen(s,l);
						break;
					case 's':
					case 'S':
						str=va_arg(ap,char*);
						l=strlen(str);
						if(sdsavible(s)<l)
							sdsMakeRoomfor(s,l);
						memcpy(s+i,str,l);
						i+=l;
						sdsinclen(s,l);
						break;
					default:
						s[i++]=next;
						sdsinclen(s,1);
						break;
				}
				break;
			default:
				s[i++]=*f;
				sdsinclen(s,1);
				break;
				}
		f++;
		}
	va_end(ap);
	s[i]='\0';
	return s;
}

sds sdstrim(sds s, const char *cset) {
    char *start, *end, *sp, *ep;
    size_t len;

    sp = start = s;
    ep = end = s+sdslen(s)-1;
    while(sp <= end && strchr(cset, *sp)) sp++;
    while(ep > sp && strchr(cset, *ep)) ep--;
    len = (sp > ep) ? 0 : ((ep-sp)+1);
    if (s != sp) memmove(s, sp, len);
    s[len] = '\0';
    sdssetlen(s,len);
    return s;
}

sds *sdssplitlen(const char *s, int len, const char *sep, int seplen, int *count){
    int elements = 0, slots = 5, start = 0, j;
    sds *tokens;

    if (seplen < 1 || len < 0) return NULL;

    tokens = malloc(sizeof(sds)*slots);
    if (tokens == NULL) return NULL;

    if (len == 0) {
        *count = 0;
        return tokens;
    }
    for (j = 0; j < (len-(seplen-1)); j++) {
        /* make sure there is room for the next element and the final one */
        if (slots < elements+2) {
            sds *newtokens;

            slots *= 2;
            newtokens = realloc(tokens,sizeof(sds)*slots);
            if (newtokens == NULL) goto cleanup;
            tokens = newtokens;
        }
        /* search the separator */
        if ((seplen == 1 && *(s+j) == sep[0]) || (memcmp(s+j,sep,seplen) == 0)) {
            tokens[elements] = sdsnewlen(s+start,j-start);
            if (tokens[elements] == NULL) goto cleanup;
            elements++;
            start = j+seplen;
            j = j+seplen-1; /* skip the separator */
        }
    }
    /* Add the final element. We are sure there is room in the tokens array. */
    tokens[elements] = sdsnewlen(s+start,len-start);
    if (tokens[elements] == NULL) goto cleanup;
    elements++;
    *count = elements;
    return tokens;

cleanup:
    {
        int i;
        for (i = 0; i < elements; i++) sdsfree(tokens[i]);
        free(tokens);
        *count = 0;
        return NULL;
    }

}

sds *sdssplit(const char *s,const char *sep,int *count){
	return sdssplitlen(s,strlen(s),sep,strlen(sep),count);
}

char *strdup(const char *s) {
    size_t l = strlen(s)+1;
    char *p = malloc(l);

    memcpy(p,s,l);
    return p;
}	
