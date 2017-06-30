#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid,p1;
	int status;
	printf("begin\n");
	if((pid=fork())<0){
		printf("fork error");
		exit(-1);
	}else if(pid==0){
		printf("in first child pid is %d\n",getpid());
		if((pid=fork())<0){
		printf("second fork error\n");
		exit(-1);
		}else if(pid>0){
		printf("second fork in first child pid is %d\n",getpid());
		sleep(2);
		exit(7);
		}
		sleep(2);
		printf("in second child pid is %d,ppid is %d\n",getpid(),getppid());
		sleep(2);
		printf("second child end\n");
		exit(0);
	}else{
		sleep(2);
	printf("now in main parents\n");
	if(wait(&status)!=pid){
	printf("wait pid %d error\n",pid);
	}
	printf("status is %d,pid is %d,byebye\n",status,pid);
	exit(0);
	}
}
		


