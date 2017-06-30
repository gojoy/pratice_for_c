#include "apue.h"

void str_cli(FILE *fp, int sockfd);

int main(int argc, char **argv){
	printf("begin\n");
	int socketfd;
	struct sockaddr_in servaddr;

	if(argc!=2)
		err_sys("usage:ip");

	socketfd=Socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(44449);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	connect(socketfd, (struct sockaddr *)&servaddr,sizeof(servaddr));

	str_cli(stdin, socketfd);

	return 0;
}


void str_cli(FILE *fp, int sockfd) {
	int wn,length;
	char sendline[MAXLINE],recvline[MAXLINE];

	while(fgets(sendline, MAXLINE, stdin) !=NULL){
		 wn=written(sockfd,sendline, strlen(sendline));
		 printf("write %d char from sendline is %s\n",wn,sendline);

		if(readn(sockfd, recvline, wn) ==0)
			err_sys("str_cli:error");

		fputs(recvline, stdout);

	}
}
		
