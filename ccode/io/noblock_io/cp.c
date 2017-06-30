#include "apue.h"

#define MAX 500000


int main() {
	copynoblock();
	return 0;
	}

int copynoblock() {

	char buf[MAX];
	char *ptr;
	int nw,ntow;
	ntow=read(STDIN_FILENO,buf,MAX);
	fprintf(stderr,"read %d bytes\n",ntow);

	set_fl(STDOUT_FILENO,O_NONBLOCK);

	ptr=buf;

	while(ntow>0) {
		errno=0;
		nw=write(STDOUT_FILENO,ptr,ntow);
		fprintf(stderr,"w is %d,ntow is %d,errno is %d\n",nw,ntow,errno);

		if(nw>0) {
			ptr+=nw;
			ntow-=nw;
		}
	}

	clr_fl(STDOUT_FILENO,O_NONBLOCK);

	return 0;
}

