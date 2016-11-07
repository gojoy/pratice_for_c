#include <apue.h>

int main(void)
{
    struct stat statbuf;
    if(chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0)
        err_sys("chmod error");
    exit(0);
}
