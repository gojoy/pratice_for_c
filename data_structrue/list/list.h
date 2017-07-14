#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void err_sys(const char *fmt,...);

typedef int Elem;

struct Node;

typedef struct Node node;
typedef struct Node *pNode;
typedef  pNode *List;

struct Node {
	Elem elem;
	pNode next;
};

List newList(void);

pNode newNode(Elem e);

int isEmpty(List l);

int insertToEnd(List l,Elem elem);

int showList(List l);

int countNum(List l);

int showNode(pNode p);

pNode getNodeByElem(List l, Elem elem);


int deleteNodeByElem(List l, Elem elem);

int reversalList(List l);


List newList() {
	List list;
	list=(List)malloc(sizeof(pNode));
	if(list==NULL)
		err_sys("malloc false");
	memset(list,0,sizeof(pNode));
	return list;
}


int isEmpty(List l) {
	if ((*l)==NULL)
		return 1;
	else
		return 0;
}

pNode newNode(Elem e) {
	pNode p;

	if( ( p=(pNode)malloc(sizeof(node)))==NULL )
		err_sys("malloc faile");
	memset(p,0,sizeof(node));

	p->elem=e;
	p->next=NULL;
	return p;
}

int insertToEnd(List l,Elem el) {

	if(isEmpty(l)) {
		pNode p;
		p=newNode(el);
		*l=p;
		return 1;
	}

	pNode p,ptmp;
	p=newNode(el);
	ptmp=*l;
	while(ptmp->next!=NULL)
		ptmp=ptmp->next;
	ptmp->next=p->next;
	ptmp->next=p;
	return 1;
}

int showList(List l){
	int s;
	int i=0;
	s=isEmpty(l);
	if(!s) {
		pNode p;
		p=*l;
		while(p!=NULL){
			printf("%d -> ",p->elem);
			p=p->next;
			i++;
		}
		printf("NULL\n");
	}else
		printf("list empty\n");
	return !s;
}

int countNum(List l) {
	if(isEmpty(l))
		return 0;

	int c=1;
	pNode p;
	p=*l;
	while( (p=p->next)!=NULL)
		++c;
	return c;

}

int showNode(pNode p) {
	if(p==NULL){
		printf("node is empty\n");
		return 0;
	}
	printf("node elem is %d\n",p->elem);
}

pNode getNodeByElem(List l, Elem elem) {
	if(isEmpty(l))
		return NULL;
	pNode p;
	p=*l;
	while(p!=NULL&&p->elem!=elem){
		p=p->next;
	}
	return p;
}

pNode getPreNodeByElem(List l, Elem elem) {
	
	if(isEmpty(l))
		return NULL;
}

int deleteNodeByElem(List l,Elem elem) {
	if(isEmpty(l))
		return 0;

	pNode p;
	p=*l;
	if(p->elem==elem){
		*l=p->next;
		p->next=NULL;
		free(p);
		return 1;
	}

	pNode delp;
	delp=p->next;
	showNode(delp);

	while(delp!=NULL) {
		if(delp->elem==elem) {
			p->next=delp->next;
			delp->next=NULL;
			free(delp);
			return 1;
		}
		p=delp;
		delp=delp->next;
	}
	return 0;
}

int reversalList(List l) {
	if(isEmpty(l))
		return 0;
	if( (*l)->next==NULL)
		return 1;

	pNode p,temp;
	p=*l;
	temp=p->next;
	*l=NULL;
	while(temp!=NULL) {
		p->next=*l;
		*l=p;
		p=temp;
		temp=temp->next;
	}
	p->next=*l;
	*l=p;
}



void err_sys(const char *fmt,...)
{
        printf("error:%s\n",fmt);
    exit(-1);
}

