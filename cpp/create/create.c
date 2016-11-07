#include "apue.h"
#include <fcntl.h>

char buf1[]="abc";
char buf2[]="abc";
char buf[1024];

int main(void)
{
    int fd,fd3,fd4;
    int fd1;
    if((fd=creat("file1.hole",FILE_MODE))<0)
    err_sys("create error");

    if(write(fd,buf1,3)!=3)
    err_sys("write error");
    
    if(lseek(fd,16384,SEEK_SET)==-1)
        err_sys("lseek error");

    if(write(fd,buf2,3)!=3)
        err_sys("write error");
    
    if((fd1=dup(fd))<0)
        err_sys("dup error"); 

    if((close(fd1))<0)
        err_sys("close error");

    if((fd3=open("./file1.hole",O_RDWR))<0)
        err_sys("open error");

    if((fd4=dup(fd3))<0)
        err_sys("dup fd3 error");

    if(read(fd4,buf,5)!=5)
        err_sys("read error");

    printf("%s",buf);

    exit(0);
}
