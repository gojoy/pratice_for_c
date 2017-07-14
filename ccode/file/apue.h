#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>

//#if defined(MACOS)
#include<sys/ioctl.h>
//#endif

#include <errno.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <fcntl.h>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define MAXLINE 64

static int pfd1[2],pfd2[2];

void err_msg(const char *,...);
void err_dump(const char *,...);
void err_quit(const char *,...);
void err_ret(const char *,...);
void err_cont(const char *,...);
void err_sys(const char *,...);
void err_exit(const char *,...);
void set_fl(int,int);
void clr_fl(int,int);

void TELL_WAIT();

static void
err_doit(int errnoflag,int error,const char *fmt,va_list ap)
{
    char buf[4096];
    vsnprintf(buf,4098,fmt,ap);
    if(errnoflag)
        snprintf(buf+strlen(buf),4096-strlen(buf)-1,": %s",strerror(error));
    strcat(buf,"\n");
    fflush(stdout);
    fputs(buf,stderr);
    fflush(NULL);
}

void err_sys(const char *fmt,...)
{
	printf("error:%s\n",fmt);
    exit(-1);
}


int Socket(int family, int type, int protocol) {
	int n;
	if( ( n=socket(family,type,protocol)) <0)
		err_sys("socket failed");

	return n;

}

int Bind(int socketfd,  struct sockaddr *seraddr, socklen_t addrlen){
	int n;
	if( (n=bind(socketfd, seraddr,addrlen)) <0)
		err_sys("bind error");

	return 0;
}

int Listen(int socketfd, int backlog){
	int n;
	if( ( n=listen(socketfd, backlog) ) <0 )
		err_sys("listen failed");

	return 0;

}


ssize_t readn(int fd, void *buff, size_t nbytes) {
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr=buff;
	nleft=nbytes;

	while(nleft >0) {
		if( ( nread=read(fd, ptr, nleft) ) <0) {
			if(errno == EINTR)
				nread=0;
			else
				return -1;
		}else if ( nread==0)
			break;
		nleft=nleft-nread;
		ptr=ptr+nread;
	}
	return (nbytes-nleft);
}

ssize_t written(int fd, const void *vptr, size_t n){
	size_t nleft;
	ssize_t nwrite;
	const char *ptr;

	ptr=vptr;
	nleft=n;
	while(nleft>0) {
		if( (nwrite=write(fd, ptr, nleft))<=0) {
			if (nwrite <0 && errno == EINTR)
				nwrite=0;
			else
				return -1;
		}
		nleft=nleft-nwrite;
		ptr=ptr+nwrite;
	}

	return n;
}

ssize_t readline( int fd, void *vptr, size_t maxlen) {
	ssize_t n,rc;
	char c, *ptr;

	ptr=vptr;
	for(n=1; n<maxlen; n++) {
again:
		if( (rc=read(fd,&c,1))==1 ) {
			*ptr++=c;
			if(c=='\n')
				break;
		} else if (rc==0) {
			*ptr=0;
			return(n-1);
		} else {
			if( errno==EINTR)
				goto again;
			return -1;
		}
	}
		*ptr=0;
		return n;
	}

void set_fl(int fd,int flags) {

	int val;
	if( (val=fcntl(fd,F_GETFL,0))<0){
		fprintf(stderr,"fctnl F_GETFL error\n");
		return ;
	}

	val |=flags;

	if(fcntl(fd,F_SETFL,val)<0){
		fprintf(stderr,"fctnl F_SETFL error\n");
		return ;
	}
}

void clr_fl(int fd, int flags)   
{  
    int val;  
  
    if ((val = fcntl(fd, F_GETFL, 0)) == -1) {  
	fprintf(stderr,"fctnl F_GETFL error\n");
	return ;

    }  
  
    val &= ~flags;  
  
    if (fcntl(fd, F_SETFL, val) == -1) {  
	    fprintf(stderr,"fctnl F_SETFL error\n");
	    return;
    }  
}


