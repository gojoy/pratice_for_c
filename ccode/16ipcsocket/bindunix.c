#include <stdio.h>
#include "apue.h"
#include <sys/un.h>

int main(){
	int fd,size;
	struct sockaddr_un un;
	un.sun_family=AF_UNIX;
	strcpy(un.sun_path,"foo.sock");
	size=offsetof(struct sockaddr_un,sun_path)+strlen(un.sun_path);
	if((fd=socket(AF_UNIX,SOCK_STREAM,0))<0){
		err_sys("socket faile");
	}
	if(bind(fd,(struct sockaddr*)&un,size)<0)
		err_sys("bind false");
	printf("unix socket bind\n");
	return 0;
}
