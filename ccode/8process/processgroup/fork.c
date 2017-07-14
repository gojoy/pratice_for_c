#include "../apue.h"

int gvar=6;
int val[3];

char buf[]="a write to stdout";

int main(void)
{
    int var;
    pid_t   pid;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
        err_sys("write error");

    printf("before fork\n");

    if((pid=fork())<0){
        err_sys("fork error");
}
    else if(pid==0){
	    printf("in child,pid is %ld,ppid is %ld,gpid is %ld\n",getpid(),getppid(),getpgid(0));
        gvar++;
        var++;
	val[1]=22;
	execl("/bin/bash",(char *)0);
} else{
	printf("in parents pid is %ld,ppid is %ld,gpid is %ld\n",getpid(),getppid(),getpgid(0));
	    val[1]=11;
	    printf("wait is %ld\n",wait(NULL));
    sleep(2);
}
printf("pid=%d,glob=%d,var=%d,val is %d\n",getpid(),gvar,var,val[1]);
exit(0);
}
