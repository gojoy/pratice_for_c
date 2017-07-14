#include "fifo.h"

int main() {

	Fifo f;
	if( (f=createfifo())==NULL) {
		fprintf(stderr,"init false\n");
		return 0;
	}

	if( Enfifo(f,1)<0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}

	if( Enfifo(f,2)<0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}

	if( Enfifo(f,3)<0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}

	int n;
	if( Defifo(f,&n)<0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("1 th is %d,size is %d\n",n,f->size);

	if( Defifo(f,&n)<0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("2th is %d,size is %d\n",n,f->size);

	if( Defifo(f,&n)<0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("3th is %d,size is %d\n",n,f->size);

	if( Defifo(f,&n)<0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("4th is %d,size is %d\n",n,f->size);



	return 1;
}
