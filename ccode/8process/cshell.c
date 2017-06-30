#include <stdio.h>
#include <unistd.h>

const char *env[]={"PATH=/root/code/cpp/8process:/usr/bin","USER=gg","NULL"};
int main(){
    int flag=1;
    int s;
    int e=-1;
    //const char *env[]={"PATH=/root/code/cpp/8process","USER=gg","NULL"};
    pid_t p;
    if((p=fork())<0){
        printf("error\n");
        _exit;
    }
    else
    if(p==0){
        printf("in child pid is %d flag is %d\n",getpid(),flag);
        flag++;


        //e=execl("/bin/bash","ps -a",(char*)0);
        e=execle("/bin/bash","ls","-a",(char * )0,env);
        printf("exec code %d\n",e);
        printf("after exec\n");
    }else{
        sleep(2);
        printf("exec code is %d\n",e);
        wait(&s);
        printf("child exis status is %d\n",s);
    }
    
    
        printf("in ppid id is %d flag=%d \n",getpid(),flag);
    

    return 0;
    _exit;
}
