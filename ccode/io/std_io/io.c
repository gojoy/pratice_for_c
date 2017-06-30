#include "apue.h"


int myputc(){
	char buf[MAXLINE]="hello in buf\n";
	char buf1[8];
	int c,status;

	fprintf(stderr,"buf len is %d,size is %d\n",strlen(buf),sizeof(buf));

	snprintf(buf1,8,"0123456789");


	c=0;
	while(c<8){
		status=putc(buf1[c],stdout);
		printf("c is %d,status is %d\n",c,status);
		c++;
	}

	while( (c=getc(stdin)) != EOF){
		printf("c is %d\n",c);
	}

	fputs(buf,stdout);
	return 0;
}

int mygetc(){

	int c, status, count;

	count=0;
	while( (c=getc(stdin)) != EOF){
		//printf("c is %c\n",c);
		status=putc(c,stdout);
		fprintf(stderr,"status is %c,count is %d\n",status,count);
		count++;
	}

}

int main(){

	mygetc();

}
