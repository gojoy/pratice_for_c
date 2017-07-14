#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16

//implement file structure by list

struct Node;
struct fifo;
typedef struct Node *pnode;
typedef pnode List;
typedef struct fifo *Fifo;

struct Node {
	int elem;
	pnode next;
};

struct fifo {
	int 	size;
	List	list;
	pnode	front;
	pnode	rear;
};

Fifo createfifo();
List createlist();
int InsertList(List l, int e);
pnode createpnode(int e);
int IsFull(Fifo f);
int Enfifo(Fifo f,int e);
int Defifo(Fifo f,int *e);

Fifo createfifo() {
	Fifo f;
	if( (f=malloc(sizeof(struct fifo)))==NULL) {
		fprintf(stderr,"malloc false\n");
		return NULL;
	}
	
	List l;
	if( (l=createlist())==NULL) {
		fprintf(stderr,"createlist false\n");
		return NULL;
	}

	f->list=l;
	f->front=l->next;
	f->rear=l->next;
	f->size=0;
	return f;
}

List createlist() {
	List l;
	if( (l=malloc(sizeof(struct Node)))==NULL) {
		fprintf(stderr,"malloc false\n");
		return NULL;
	}
	memset(l,0,sizeof(struct Node));
	return l;
}

pnode createpnode(int e) {
	pnode p;
	if( (p=malloc(sizeof(struct Node)))==NULL) {
		fprintf(stderr,"malloc false\n");
		return NULL;
	}

	p->elem=e;
	p->next=NULL;
}

int IsFull(Fifo f) {
	return f->size==0;
}
	
int Enfifo(Fifo f, int e) {
	pnode tmp,p;
	if( (p=createpnode(e))==NULL) {
		fprintf(stderr,"createpnode false");
		return -1;
	}

	f->front=f->list;
	tmp=f->list;
	while(tmp->next!=NULL) 
		tmp=tmp->next;
	tmp->next=p;
	f->rear=p;
	f->size++;
	return 1;
}

int Defifo(Fifo f, int *e) {
	if (IsFull(f))
		return -1;

	pnode p;
	p=f->list->next;
	*e=p->elem;
	f->list->next=p->next;
	free(p);
	f->size--;
	return 1;
}











