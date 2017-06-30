#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//char file_name="tt.file";

int makefile(){
	int fd; 
    printf("O_WRONLYis %d,O_CREAT IS %d\n",O_WRONLY,O_CREAT);
	if((fd=open("x",O_WRONLY|O_CREAT|O_TRUNC,0666))<0)
	{   
		printf("create failed\n");
		return -1;
	}   else{
		return fd;
	}
	//close(fd);
}

int testfile(){
	int fd; 
	if((fd=open("x",O_WRONLY|O_CREAT|O_EXCL))<0)
	{   
		printf("file x is exit\n");
		return -1;
	}   
	else{
		return fd;
	}
}

void writef(){
	char buf[]="create by gg in func";
	int fd=makefile();
    printf("fd is %d\n",fd);
	int size;
	if (lseek(fd,0,SEEK_CUR)==-1)
	{
		/* code */printf("cannot lseek file\n");
	}else{
		printf("ready to write\n");
		if(write(fd,buf,15)!=15){
			printf("write failed\n");
		}else{
			printf("write ok\n");
		}
	}
	

}

void main(){
	char buf[]="caretebygg";
	//makefile();
	writef();
}
