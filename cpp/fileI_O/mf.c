#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//char file_name="tt.file";

void makefile(){
    int fd;
    if((fd=open("x",O_WRONLY|O_CREAT|O_TRUNC,0666))<0)
    {
        printf("create failed\n");
    }
    close(fd);
}

void testfile(){
    int fd;
    if((fd=open("x",O_WRONLY|O_CREAT|O_EXCL))<0)
    {
        printf("file x is exit\n");
    }
}
void main(){
    makefile();
    testfile();
}
