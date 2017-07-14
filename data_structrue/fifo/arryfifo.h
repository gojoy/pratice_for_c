#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 4

struct Queue {
	int *arry;
	int cap;
	int size;
	int front;
	int rear;
};

typedef struct Queue *fifo;

fifo createfifo();
int Enfifo(fifo f,int e);
int Defifo(fifo f, int *e);
int IsEmpty(fifo f);
int IsFull(fifo f);
void showfifo(fifo f);

fifo createfifo() {
	int *a;
	fifo f;
	if( (f=malloc(sizeof(struct Queue)))==NULL) {
		fprintf(stderr,"malloc false\n");
		return NULL;
	}
	memset(f,0,sizeof(struct Queue));

	a=malloc(CAP*sizeof(int));
	memset(a,0,CAP*sizeof(int));
	f->arry=a;
	f->cap=CAP-1;
	f->size=0;
	f->front=0;
	f->rear=0;

	return f;
}

int IsEmpty(fifo f) {

	return f->size==0;
}

int IsFull(fifo f) {
	return f->size==f->cap;
}

int Enfifo(fifo f, int e) {

	int pos;
	
	if( IsFull(f)) {
		fprintf(stderr,"fifo is full, enfifo false\n");
		return 0;
	}

	pos=f->rear;
	if( pos==f->cap) {
		f->rear=0;
		f->arry[0]=e;
	}else {
		f->arry[pos+1]=e;
		f->rear++;
		f->arry[f->rear]=e;
	}
	f->size++;
	return 1;

}

int Defifo(fifo f,int *e) {
	

	if(IsEmpty(f)) {
		fprintf(stderr,"fifo empty,Defifo false\n");
		return 0;
	}

	if( f->front==f->cap) {
		f->front=0;
		*e=f->arry[0];
		f->arry[0]=0;
	} else {
		f->front++;
		*e=f->arry[f->front];
		f->arry[f->front]=0;
		//fprintf(stderr,"defifo *e is num %d,value %d\n",f->front,f->arry[f->front]);

	}

	f->size--;
	return 1;
}

		
void showfifo(fifo f) {

	int i;
	printf("show fifo\n");

	if (IsEmpty(f)) {
		fprintf(stderr,"empty fifo\n");
	}

	printf("fifo size is %d,front is %d,rear is %d\n,arry is\n",f->size,f->front,f->rear);

	for( i=0;i<CAP;i++) {
		printf("arry [%d] is %d\n",i,f->arry[i]);
	}
	
	return;
}



