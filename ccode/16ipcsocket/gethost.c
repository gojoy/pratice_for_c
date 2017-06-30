#include "apue.h"

int main(int argc,char *argv[]){
	//char buf[MAXLINE];
	struct addrinfo *ailist,*aip;
	struct addrinfo hint;
	struct hostent* h1;
	struct sockaddr_in *sinp;
	const char *addr;
	h1=gethostent();
	if(h1==NULL){
		err_sys("gethostnet false");
	}
	printf("name is %s\n",h1->h_name);

	char buf[MAXLINE];

	if(argc!=3){
		err_sys("input 3 para");
	}
	hint.ai_flags=AI_CANONNAME;
	hint.ai_socktype=0;
	hint.ai_family=0;
	hint.ai_protocol=0;
	hint.ai_addrlen=0;
	hint.ai_addr=NULL;
	hint.ai_next=NULL;
	hint.ai_canonname=NULL;
	if(getaddrinfo(argv[1],argv[2],&hint,&ailist)!=0)
		err_sys("getaddrinfo false");
	for(aip=ailist;aip!=NULL;aip=aip->ai_next){
		printf("family is %d,type is %d,protocol is %d\n",aip->ai_family,aip->ai_socktype,aip->ai_protocol);
		if(aip->ai_family==AF_INET){
			sinp=(struct sockaddr_in *)aip->ai_addr;
			addr=inet_ntop(AF_INET,&sinp->sin_addr,buf,INET_ADDRSTRLEN);
			printf("address is %s",addr);
			printf("port is %d",ntohs(sinp->sin_port));
		}
		printf("\n");
	}


}
