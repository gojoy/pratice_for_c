#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>


int getenviro(void){

    char *p;
    char *n="PATH";
    p=getenv(n);
    printf("p is %s\n",p);
    return 0;
}


int pl(int resource){

    struct rlimit  rt;
    int lim;
   if( getrlimit(resource,&rt)<0){
        printf("getrlimit error\n");
         return -1;
   }
   if(rt.rlim_cur==RLIM_INFINITY){
       printf("infinity\n");
       return 0;
   }else{
       lim=rt.rlim_cur;
       printf("%d\n",lim);
       //return rt.rlim_cur;
   }
   return lim;
    //prlimit();
}

int plim(int resource){
    struct rlimit rtnew;
    struct rlimit rtold;
    memset(&rtnew,0,sizeof(rtnew));
    memset(&rtold,0,sizeof(rtold));
    pid_t p=4468; 
    pid_t t=getpid();
    printf("pid is %d\n",t);
    bzero(&rtnew,sizeof(rtnew));

    if(prlimit(p,resource,&rtnew,&rtold)<0){
        printf("prlimit error\n");
        return -1;
}

    if (rtold.rlim_cur==RLIM_INFINITY){
        printf("infinity\n");
        return 0;
    }else{
        printf("%d\n",rtold.rlim_cur);
        return rtold.rlim_cur;
    }
return rtold.rlim_cur;

}


int main(){

//    getenviro();
    printf("cpu is %d\n",pl(RLIMIT_CPU));
    printf("data is %d\n",pl(RLIMIT_DATA));
    printf("stack is %d\n",pl(RLIMIT_STACK));
    printf("FILE IS %d\n",pl(RLIMIT_NOFILE));


    printf("\n now begin doc\n");
    

    printf("cpu is %d\n",plim(RLIMIT_CPU));
    printf("data is %d\n",plim(RLIMIT_DATA));
    printf("memory is %d\n",plim(RLIMIT_AS));
    printf("file is %d\n",plim(RLIMIT_NOFILE));
    printf("stack is %d\n",plim(RLIMIT_STACK));
    return 0;
}
