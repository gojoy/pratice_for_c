#include <stdio.h>
#include "sds.h"
#ifdef __SDS_H
#define MAX 10
#else
#define MAX 5
#endif

void testargs(int n,...) {
	int i,lim;
	va_list ap;
	int args;
	char *p;
	va_start(ap,n);
	printf("n is %d\n",n);
	for(i=0;i<n;i++ ){
		p=va_arg(ap,char*);
		printf("i is %d,args is %s\n",i,p);
	}
	va_end(ap);
}

void testcharargs(char *fmt,...){
	char *p;
	va_list ap;
	va_start(ap,fmt);
	printf("fmt is %s\n",fmt);
	p=va_arg(ap,char*);
	printf("p is %s\n",p);
	p=va_arg(ap,char*);
	printf("next is %s\n",p);
	va_end(ap);

	return;

}

int main() {
	
	int i=0,n=0;
	//testargs(3,"hello","two","three");
	printf("%d\n",MAX);
	sds s;
	s=newsds("hellohellohellohellohellohello");
	printf("%s\n",s);
	sds *str;
	str=sdssplit(s,"ll",&n);
	for(i=0;i<n;i++){
		printf("%s\n",*(str+i));
	}
	printf("n is %d\n",n);

	/*
	printf("s is %s,\n",s);
	showsds(s);
	sdscat(s,"world");
	showsds(s);
	sdscpy(s,"change!");
	showsds(s);
	*/
	//s=sdsfmt(s,"abcd name is %s,score is %i","gg",11);
	//showsds(s);

}
