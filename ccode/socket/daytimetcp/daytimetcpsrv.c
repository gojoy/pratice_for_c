#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 64
void err_sys(char *meg){
	printf("%s\n",meg);
	exit(-1);
}

int main(int argc, char **argv) {
	int socketfd,confd,  n;
	socklen_t len;
	char buff[MAXLINE];
	struct sockaddr_in servaddr, cliaddr;
	time_t ticks;

	if( (socketfd = socket(AF_INET,SOCK_STREAM,0))<0)
		err_sys("socket falied");


	
	bzero(&servaddr,sizeof(servaddr));
	bzero(&cliaddr,sizeof(cliaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if( (bind(socketfd,(struct sockaddr *)&servaddr, sizeof(servaddr))<0))
		err_sys("bind error");

	listen(socketfd, 5);

	while(1){
		len =sizeof(cliaddr);
		confd =accept(socketfd, (struct sockaddr *)&cliaddr, &len);
		printf("connection from %s,port %d\n",inet_pton(AF_INET, &cliaddr.sin_addr, buff,sizeof(buff)),ntohs(cliaddr.sin_port));
		ticks=time(NULL);
		snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));

		write(confd,buff,sizeof(buff));

		close(confd);
	}
}



