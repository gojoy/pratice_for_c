#include "apue.h"
#include <ctype.h>

int main(){
	char buf[MAXLINE];
	int n,n1,n2;
	while((n=read(STDIN_FILENO,buf,MAXLINE))>0){
		//buf[n]=0;
		fputs(buf,stdout);
		if(sscanf(buf,"%d%d",&n1,&n2)==2){
			sprintf(buf,"%d\n",n1+n2);
			n=strlen(buf);
			if(write(STDOUT_FILENO,buf,n)!=n)
				err_sys("write false");
		}else{
			fputs("invalid args\n",stdout);
			fflush(stdout);
		}
	}
	return 0;
}
