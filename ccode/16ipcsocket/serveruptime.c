#include "demo.h"

#define BUFLINE 128
#define QLEN 10

//#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256

extern int initserver(int,const struct sockaddr *,socklen_t,int);

void server(int sockfd){
	int clfd;
	FILE *fp;
	char buf[BUFLINE];
	
	//set_cloexec(sockfd);
	while(1){
		if((clfd=accept(sockfd,NULL,NULL))<0)
			err_sys("accept false");

		if((fp=popen("/usr/bin/uptime","r"))==NULL){
			sprintf(buf,"err:%s\n",strerror(errno));
			send(clfd,buf,strlen(buf),0);
		}else{
			while(fgets(buf,BUFLINE,fp)!=NULL){
				send(clfd,buf,strlen(buf),0);
			}
			pclose(fp);
			close(clfd);
		}
	}

			



}

int main(int argc,char *argv[]){
	printf("begin\n");
	struct addrinfo *ailist,*aip;
	struct addrinfo hint;
	int sockfd,err,n;
	char *host;

	if(argc!=1){
		printf("argc is %d\n",argc);

		err_sys("usage:uptime!");
	}

	if((n=sysconf(_SC_HOST_NAME_MAX))<0)
		n=HOST_NAME_MAX;

	if((host=malloc(n))==NULL)
		err_sys("malloc false");
	if(gethostname(host,n)<0)
		err_sys("gethostname false");
	//daemonize("ruptime");
	memset(&hint,0,sizeof(hint));
	hint.ai_flags=AI_CANONNAME;
	hint.ai_socktype=SOCK_STREAM;
	hint.ai_canonname=NULL;
	hint.ai_addr=NULL;
	hint.ai_next=NULL;

	if((err=getaddrinfo(host,"mysql",&hint,&ailist))!=0){
		printf("host is %s\n",host);
		err_sys("getaddrinfo false");
	}

	for(aip=ailist;aip!=NULL;aip=aip->ai_next){
		if((sockfd=initserver(SOCK_STREAM,aip->ai_addr,aip->ai_addrlen,QLEN))>=0){
			server(sockfd);
			exit(0);
		}
	}
	exit(1);
}
















