#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXLINE 64

void err_sys(char *meg){
	printf("%s\n",meg);
	exit(-1);
}
int main(int argc, char **argv){
	int socketfd, n;
	char recvline[MAXLINE];
	struct sockaddr_in servaddr;

	if(argc !=2){
		err_sys("usage:ip");
	}

	if( (socketfd = socket(AF_INET,SOCK_STREAM,0))<0)
		err_sys("socket falied");

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <=0)
		err_sys("inet_pton error");

	if(connect(socketfd, ( struct sockaddr *)&servaddr, sizeof(servaddr))<0)
		err_sys("connect error");

	while( (n=read(socketfd, recvline, MAXLINE))>0) {
		recvline[n]=0;
		if(fputs(recvline,stdout)==EOF)
			err_sys("fputs error");
	}

	if (n<0)
		err_sys("read error");

	exit(0);

}

