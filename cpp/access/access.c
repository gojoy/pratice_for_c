#include <apue.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    if(argc!=2)
        printf("usage: pathname\n");

    if(access(argv[1],R_OK)<0)
        err_ret("access error %s",argv[1]);
    else
    printf("read access  OK\n");

    if(open(argv[1],O_RDONLY)<0)
        err_ret("open error for %s",argv[1]);
    else
        printf("open OK\n");
    exit(0);
}
