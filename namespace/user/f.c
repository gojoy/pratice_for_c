#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int status;
	pid_t pid;
	if ( (pid=fork())<0 ) {
		printf("fork false\n");
		exit(1);
	}
	if(pid >0 ) {
		sleep(5);
		printf("in parents\n");
		printf("uid=%d,euid =%d\n",getuid(),geteuid() );
		if(wait(&status)!=pid) {
		printf("wait error\n");
		exit(1);
	}
	} else if(pid==0) {
		printf("in child!\n");
		printf("uid=%d,euid =%d\n",getuid(),geteuid() );
	}

	return 0;
}
