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

#define STACK_SIZE (1024*1024)

static char child_stack[1024*1024];
char* const child_args[]={
    "/bin/bash",
    NULL};

int child_main(void* args){
    printf("in chlid process\n");
    sethostname(" NewNamespace",12);
    execv(child_args[0],child_args);
    return 1;
    }

int main()
{
    printf("begin\n");
    int child_pid;
    child_pid= clone(child_main,child_stack+STACK_SIZE,CLONE_NEWPID|CLONE_NEWUTS|SIGCHLD,NULL);
    waitpid(child_pid,NULL,0);
    printf("end\n");
    //int c=0;
    /*p1=fork();
    if(p1<0)
    {
    printf("Hello world!\n");
    }else if(p1==0)
    {printf("i am child,pid =%d\n",getpid());
    }else
        {printf("i am parent,pid=%d\n",getpid());
        }*/
    return 0;
}

