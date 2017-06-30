#include <sys/types.h>
#include<sys/stat.h>
#include<sys/termios.h>
#if defined(MACOS)
#include<sys/ioctl.h>
#endif

#include <errno.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void err_msg(const char *,...);
void err_dump(const char *,...);
void err_quit(const char *,...);
void err_ret(const char *,...);
void err_cont(const char *,...);
void err_sys(const char *,...);
void err_exit(const char *,...);

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
    va_list     ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    exit(1);
}


