#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
typedef struct Node *ptrnode;
typedef ptrnode stack;

int isempty(stack s);
stack createstack();
int deletestack(stack s);
int push(int elem,stack S);
int pop(stack s);
int top(stack s,int *elem);
ptrnode newenode(int elem);

struct Node {
	int Elem;
	ptrnode Next;
};

stack createstack() {
	stack s;
	if( (s=(stack)malloc(sizeof(struct Node)))==NULL){
			fprintf(stderr,"malloc false\n");
			return NULL;
	}
	memset(s,0,sizeof(struct Node));
	s->Next=NULL;
	return s;
}

int isempty(stack s) {

	if(s->Next==NULL) 
		return 1;
	return 0;

}

int pop(stack s){

	if(isempty(s))
		return 0;

	ptrnode p;
	p=s->Next;
	s->Next=p->Next;
	free(p);
	return 1;
}

int deletestack(stack s) {

	while(!isempty(s))
		pop(s);
	free(s);
	return 1;
}

int top(stack s,int *e) {

	if(isempty(s)){
		fprintf(stderr,"null stack\n");
		return 0;
	}

	*e=s->Next->Elem;

	if(pop(s))
		return 1;
	return 0;
}

int push(int elem,stack s) {

	ptrnode p;
	if( (p=newenode(elem))==NULL) {
		fprintf(stderr,"newnode false\n");
		return 0;
	}

	p->Next=s->Next;
	s->Next=p;

	return 1;

}

ptrnode newenode(int elem) {
	ptrnode p;
	if( (p=malloc(sizeof(struct Node)))==NULL) {
		fprintf(stderr,"malloc node false\n");
		return NULL;
	}

	p->Elem=elem;
	p->Next=NULL;

	return p;
}















	






