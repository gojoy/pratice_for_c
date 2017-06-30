#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void sig_usr(int sig);


int main(){
    
    if(signal(SIGUSR1,sig_usr)==SIG_ERR)
    {
        printf("signal error\n");
    }

    while(1){
        pause();
    }

    return 0;
}


static void sig_usr(int sig){

    if(sig==SIGUSR1){
        printf("revice sigusr1\n");
    }else 
        if(sig==SIGUSR2){
            printf("recive sigusr2\n");
        }



}
