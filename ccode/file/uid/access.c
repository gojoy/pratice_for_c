#include "../apue.h"
#include <fcntl.h>

int main(int argc,char *argv[])
{

	printf("uid=%d,gid=%d\n",getuid(),getgid());
	printf("euid=%d,egid=%d\n",geteuid(),getegid());

    if(argc!=2) {
        printf("usage: pathname\n");
	return 0;
    }

    if(access(argv[1],R_OK)<0)
        printf("access read error %s\n",argv[1]);
    else
    printf("read access  OK\n");

    if(access(argv[1],W_OK)<0) {
	    printf("access write error %s\n",argv[1]);
    } else {
	    printf("access write ok\n");
    }

    if( open(argv[1],O_RDWR)<0) {
	    printf("cannot open with rw\n");
    }else {
	    printf("open with rw ok\n");
    }

    exit(0);
}
