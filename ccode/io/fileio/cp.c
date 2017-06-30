#include <unistd.h>
#include <stdio.h>

#define MAX 4

char out[]="\toutput is :";

int copy();
 
int showbuf(char *buf);

int main() {
	//printf("begin\n");

	copy();

}

int copy() {

	char buf[MAX];
	memset(buf,0,MAX);
	int n,m;
	int count=0;
	while( (n=read(STDIN_FILENO,buf,MAX))>0) {
		//showbuf(buf);

		//write(STDOUT_FILENO,out,sizeof(out));
		if ( (m=write(STDOUT_FILENO,buf,MAX))!=MAX) {
		//	printf("write %d\n\n",m);
			exit(0);
		}
		count++;
	//	memset(buf,0,MAX);
	}

	//printf("\nDone,read %d tmies\n",count);
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
