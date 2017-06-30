#include "../apue.h"
#include <netinet/in.h>

void str_echo(int sockfd);
void str_echo1(int sockfd);
void sig_chld(int signo);

int main() {
	char buf[MAXLINE];
	int maxfd, i, maxi;
	int nready, client[FD_SETSIZE], n;
	int listenfd, connfd, sockfd;
	socklen_t clilen;
	struct sockaddr_in cliaddr, srvaddr;
	fd_set rset, allset;

	listenfd=Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&srvaddr, sizeof(srvaddr));

	srvaddr.sin_family=AF_INET;
	srvaddr.sin_port=htons(44449);
	srvaddr.sin_addr.s_addr=htons(INADDR_ANY);

	Bind(listenfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));

	Listen(listenfd,10);

	//signal(SIGCHLD,sig_chld);

	maxfd=listenfd;
	maxi=-1;
	for(i=0; i<FD_SETSIZE; i++)
		client[i]=-1;

	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);

	while(1) {
		rset=allset;
		if( nready=select(maxfd+1,&rset,NULL,NULL,NULL) <0 )
			err_sys("select error");

		if( FD_ISSET(listenfd, &rset)){
			clilen=sizeof(cliaddr);
			if( (connfd=accept(listenfd, (struct sockaddr *)&cliaddr, &clilen))<0){
				if(errno==EINTR)
					continue;
				else
					err_sys("accept error");
			}

			printf("accept connect\n");

			for(i=0; i<FD_SETSIZE; i++){
				if(client[i]<0) {
					client[i]=connfd;
					break;
				}
			}
			if(i==FD_SETSIZE)
				err_sys("too many clents");

			FD_SET(connfd, &allset);

			if(connfd>maxfd)
				maxfd=connfd;

			if(i>maxi)
				maxi=i;

			printf("i is %d,connfd is %d,nready is %d,listenfd is %d,maxi is %d\n",i,connfd,nready,listenfd,maxi);

			if(--nready<=0)
				continue;
		}
		
		for(i=0; i<=maxi; i++){
			sockfd=client[i];
			if(sockfd<0)
				continue;
			if( FD_ISSET(sockfd, &rset)){
				printf("sockfd read \n");
				if( (n=read(sockfd, buf, MAXLINE))==0) {
					close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i]=-1;
				}else{
					written(sockfd, buf, n);
				}

				if(--nready<=0)
					break;
			}
		}
	}
}

void str_echo1(int sockfd){
	ssize_t n;
	char buf[MAXLINE];
	char out[]="read null in server";
	if( (n=read( sockfd, buf, MAXLINE))==0) {
		fputs(out, stdout);
		close(sockfd);
	} else{
		written(sockfd, buf, n);
	}
}

void str_echo(int sockfd){
	ssize_t n;
	char buf[MAXLINE];

again:
	while( (n=read(sockfd, buf, MAXLINE)) >0){
		written(sockfd, buf, n);
	}
	if(n<0 && errno==EINTR)
		goto again;
	else if(n<0)
		err_sys("str_echo:read error");
}

void sig_chld(int signo) {
	pid_t pid;
	int stat;

	while( (pid=waitpid(-1,&stat,WNOHANG)) >0)
		printf("child %d terminated\n",pid);
	return;
}
