#include <unistd.h>
#define _GNU_SOURCE        /* or _BSD_SOURCE or _SVID_SOURCE */
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <sys/types.h>
#include <sched.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#define SHELL "/bin/sh"
	//char cmd[60];
	int pf(char *cmd)
{
	//char cmd[]={"ls -hl"};
	pid_t fp;
	int c=0;
	fp=fork();
	if(fp<0)	printf("error/n");
	else if (fp==0){
	printf("child,pid is %d\n",getpid());
	execl(SHELL,SHELL,"-c",cmd,NULL);
	waitpid(fp,NULL,0);
	//_exit(EXIT_FAILURE);
	}
	else{
	printf("parent,pid is %d\n",getpid());
	waitpid(fp,NULL,0);

	}
	//printf("fp=%d\n",fp);
	return 0;
}

int main()
{
char *p="ls -hl";
pf(p);
return 0;
}
