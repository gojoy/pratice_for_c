#include "apue.h"

int maxi(int,int);
void str_cli(FILE *fp, int sockfd);
char readerr[16]="read eof\n";

int main(int argc, char **argv){
	printf("begin\n");
	int socketfd;
	struct sockaddr_in servaddr;

	/*
	if(argc!=2)
		err_sys("usage:ip");
*/
	socketfd=Socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(44449);
	inet_pton(AF_INET, "115.28.149.105", &servaddr.sin_addr);

	connect(socketfd, (struct sockaddr *)&servaddr,sizeof(servaddr));

	str_cli(stdin, socketfd);

	return 0;
}


void str_cli(FILE *fp, int sockfd) {

	int stdineof;
	int maxfdp1;
	fd_set rset;
	int wn,length,rn;
	char sendline[MAXLINE],recvline[MAXLINE];

	FD_ZERO(&rset);
	stdineof=0;

	while(1) {
		FD_SET(sockfd,&rset);
		if (stdineof==0)
			FD_SET(fileno(fp), &rset);

		maxfdp1=maxi(fileno(fp),sockfd)+1;

		if( select(maxfdp1, &rset, NULL, NULL, NULL)<0 )
			err_sys("select error");

		if(  FD_ISSET(sockfd, &rset)) {
			printf("socket is readable\n");
			if( (rn=read(sockfd, recvline, MAXLINE) ) == 0){
				if (stdineof==1)
					return;
				else
					err_sys("read error:server terminated prematurely");
			}
			if(write(STDERR_FILENO, recvline, rn)!=rn)
				err_sys("output error");
		}

		if( FD_ISSET(fileno(fp), &rset)) {
			printf("input is readable\n");
			if( (wn=read(fileno(fp),sendline, MAXLINE)) == 0){
				stdineof=1;
				write(STDOUT_FILENO,readerr, 16);
				//printf("fgets stdin error");
				shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}

			written(sockfd, sendline, wn);
			//printf("write %d char to sockfd is %s \n",wn,sendline);
		}

	}

}

int maxi(int a,int b) {
	if(a>b)
		return a;
	else
		return b;
}
		
