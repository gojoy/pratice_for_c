#include <math.h>
#include <stdio.h>
#include "sparkline.h"

int main(int argc, char const *argv[]){

	char *s=" 1,2,3,4,5,6,7,8,9,10,10,8,5,3,1";
	int a;
	sds out;
	out=sdsempty();
	struct sequence *seq;
	seq=argument_to_sequence(s);
	out=sparklineRender(out,seq,6,1,1);
	printf("%s\n",out);

}
