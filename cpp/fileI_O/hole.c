#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int makeholefile(){
 int fd;
fd=openat(AT_FDCWD,"file2",O_RDWR|O_CREAT,0666);
if (fd>0){
printf("create ok\n");
if(lseek(fd,0,SEEK_CUR)==-1){
    printf("cannot set seek\n");
}else{
    printf("set ok\n");
}
return fd;
}else{
    printf("error\n");
     exit(0);
}
}
int testfile(){
    int fd;
    fd=openat(AT_FDCWD,"file3",O_RDWR);
    if (fd<0){
        printf("no file\n");
        exit(0);
    }else{
        return fd;
}
}

void findseek(){
    off_t pos;
    int fd;
    if(fd=testfile()!=-1){
    pos=lseek(fd,0,SEEK_CUR);
    if(pos==-1){
        printf("canot set seek\n");
    }else{
            printf("ok\n");
        }
    }else{
        printf("error\n");
    }
}
void main(){
printf("ok\n");
int x=makeholefile();
int c=testfile();
//findseek();
//testfile();
}
