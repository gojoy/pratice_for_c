#include <apue.h>

int gvar=6;

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
        gvar++;
        var++;
}
    else{
    sleep(2);
}
printf("pid=%d,glob=%d,var=%d\n",getpid(),gvar,var);
exit(0);
}
