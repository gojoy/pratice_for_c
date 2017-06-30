#include "../apue.h"
#include <netinet/in.h>

void str_echo(int sockfd);

int main() {
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, srvaddr;

	listenfd=Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&srvaddr, sizeof(srvaddr));

	srvaddr.sin_family=AF_INET;
	srvaddr.sin_port=htons(44449);
	srvaddr.sin_addr.s_addr=htons(INADDR_ANY);

	Bind(listenfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));

	Listen(listenfd,5);

	while(1) {
		clilen=sizeof(cliaddr);
		connfd=accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

		if( (childpid=fork()) ==0){
			close(listenfd);
			str_echo(connfd);
			exit(0);
			}
		close(connfd);
	}

}

void str_echo(int sockfd){
	ssize_t n;
	char buf[MAXLINE];

again:
	while( (n=read(sockfd, buf, MAXLINE)) >0){
		write(sockfd, buf, n);
	}
	if(n<0 && errno==EINTR)
		goto again;
	else if(n<0)
		err_sys("str_echo:read error");
}
