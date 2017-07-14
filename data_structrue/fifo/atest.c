#include "arryfifo.h"

int main() {

	fifo f;
	if( (f=createfifo())==NULL) {
		fprintf(stderr,"init false\n");
		return 0;
	}

	//showfifo(f);

	if( Enfifo(f,1)<0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}
	 //showfifo(f);

	if( Enfifo(f,2)==0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}
	 //showfifo(f);

	if( Enfifo(f,3)==0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}

	//showfifo(f);

	int n;
	if( Defifo(f,&n)==0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("1 th is %d,size is %d\n",n,f->size);

	if( Enfifo(f,4)==0) {
		fprintf(stderr,"enfifo false\n");
		return 0;
	}
	//showfifo(f);

	if( Defifo(f,&n)==0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("2th is %d,size is %d\n",n,f->size);

	if( Defifo(f,&n)==0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("3th is %d,size is %d\n",n,f->size);

	if( Defifo(f,&n)==0) {
		fprintf(stderr,"defifo false\n");
		return 0;
	}

	printf("4th is %d,size is %d\n",n,f->size);

	//showfifo(f);
	return 1;
}
