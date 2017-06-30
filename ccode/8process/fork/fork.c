#include "apue.h"

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
	    printf("in child\n");
        gvar++;
        var++;
	val[1]=22;
}
    else{
	    val[1]=11;
    sleep(2);
}
printf("pid=%d,glob=%d,var=%d,val is %d\n",getpid(),gvar,var,val[1]);
exit(0);
}
