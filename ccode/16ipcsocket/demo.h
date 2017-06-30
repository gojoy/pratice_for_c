#include "apue.h"
#define MAXSLEEP 128

int connect_retry(int domain,int type,int protocol,const struct sockaddr *addr,socklen_t alen);

int initserver(int type,const struct sockaddr *addr,socklen_t alen,int qlen);




int connect_retry(int domain,int type,int protocol,const struct sockaddr *addr,socklen_t alen){
	int numsec,fd;

	for(numsec =0;numsec<MAXSLEEP;numsec=numsec*2){
		if((fd=socket(domain,type,protocol)<0))
			return -1;
		if(connect(fd,addr,alen)==0){
			return fd;
		}
		close(fd);

		if(numsec<=MAXSLEEP/2)
			sleep(numsec);
	}
	return -1;
}


int initserver(int type,const struct sockaddr *addr,socklen_t alen,int qlen){
	int fd;
	int err=0;

	if((fd=socket(addr->sa_family,type,0))<0)
		return -1;
	if(bind(fd,addr,alen)<0)
		goto errout;
	if(type==SOCK_STREAM||type==SOCK_SEQPACKET){
		if(listen(fd,qlen)<0)
			goto errout;
	}
	return fd;

errout:
	err=errno;
	close(fd);
	errno=err;
	return -1;
}


