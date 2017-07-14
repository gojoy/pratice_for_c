#include "list.h"
#include <stdio.h>

#define MAX 8
#define S 2

char buf[MAX];

void add(List l);
void del(List l);
int handle(char c,List l);
void dealin();

char input;

char  usage[]="usage:\n q--quit\n s--show list \n a--add elem\n d--delete elem\n t--traversal list\n";

int main() {
	char input[S];
	char c;
	memset(input,S,sizeof(char));
	List l;
	l=newList();

	//fputs(usage,stdout);

	while( (fgets(input,S,stdin))!=NULL){
		c=input[0];
		dealin();
		handle(c,l);
		
	}
}

void dealin() {
	char buf[256];
	fgets(buf,256,stdin);
}

int handle(char c,List l) {
	switch(c)
	{
		case 'q':
			printf("bye");
			exit(1);
			break;
		case 's':showList(l);
			 break;
		case 'a':add(l);
			 break;
		case 'd':del(l);
			 break;
		case 't':reversalList(l);
			 printf("reversal list\n");
			 break;
		default:fputs(usage,stdout);
			break;
	}
	return 1;
}



void add(List l) {
	printf("input add elem\n");
	int e;
	fgets(buf,MAX,stdin);
	if( (e=atoi(buf))==0) {
		printf("get num false\n");
		return;
	}
	if(!insertToEnd(l,e)){
		printf("insert false");
		return;
	}
	printf("insert %d\n",e);
	
}

void del(List l) {
	printf("input del elem\n");
	int e;
	fgets(buf,MAX,stdin);
	if( (e=atoi(buf))==0) {
		printf("get num false\n");
		return;
	}
	if( !deleteNodeByElem(l,e)){
		printf("delete false\n");
		return;
	}
	printf("delete %d\n",e);
}

