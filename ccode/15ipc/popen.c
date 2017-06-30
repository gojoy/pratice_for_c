#include "apue.h"

int main(){
	int c;
	FILE *p1;
	p1=popen("ps ","r");
	c=fgetc(p1);
	while(c!=EOF){
	//putchar(c);
	printf("%c",c);
	c=fgetc(p1);}
	printf("exec\n");
	pclose(p1);
	printf("end\n");
}
