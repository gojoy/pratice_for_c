#include <unistd.h>
#include <stdio.h>

#define MAX 4

char out[]="\toutput is :";

int copy();
 
int showbuf(char *buf);

int detail_read();

int handlebuf(char *buf);

int main() {
//	printf("begin\n");


	detail_read();
}

int copy() {

	char buf[MAX];
	memset(buf,0,MAX);
	int n,m;
	int count=0;
	while( (n=read(STDIN_FILENO,buf,MAX))>0) {

		if ( (m=write(STDOUT_FILENO,buf,MAX))!=MAX) {
			exit(0);
		}
		count++;
	//	memset(buf,0,MAX);
	}

//	printf("\nDone,read %d tmies\n",count);
}

int showbuf(char *buf) {
	printf("\nshowbuf\n");
	int i;
	if(buf==NULL) 
		return -1;
	for(i=0;i<MAX;i++)
		printf("%d ",buf[i]);
	printf("\n");
}

int detail_read() {
	int r,w;
	char buf[MAX];
	memset(buf,0,MAX);
	while(1){

	//	memset(buf,0,MAX);

		r=read(STDIN_FILENO,buf,MAX);

		if(r<MAX)
			break;

		write(STDOUT_FILENO,buf,MAX);

	}

	if(r==0)
		return 1;


	handlebuf(buf);

	write(STDOUT_FILENO,buf,MAX);


}

int handlebuf(char *buf){
	int i;
	for(i=0;i<MAX;i++)
		if(buf[i]==10)
			break;
	for(;i<MAX;i++){
		buf[i]=0;
	}
	return 1;
}

