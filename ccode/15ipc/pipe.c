#include "apue.h"
#include <time.h>

void main(){
	int fd[2];
	int n;
	pid_t pid;
	char line[MAXLINE];
	char *msg="send from child\n";
	
	if(pipe(fd)<0){
		err_sys("pipe false");
	}
	if((pid=fork())<0){
		err_sys("fork false");
	}else if(pid==0){
		printf("in child\n");
		sleep(5);
		close(fd[0]);
		write(fd[1],"sendfromchild",14);
	}else{
		printf("in parents\n");
		time_t timep; 
		time (&timep); 
		printf("%s",asctime(gmtime(&timep)));
		close(fd[1]);

		n=read(fd[0],line,MAXLINE);
		printf("read from child is\t %s,num is %d\n",line,n);
		time (&timep); 
		printf("%s",asctime(gmtime(&timep)));
		sleep(2);

	}
	printf("main common part\n");
	exit(0);
}
