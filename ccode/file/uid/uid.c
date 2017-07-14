#include "../apue.h"

int main(){
    printf("uid=%d,gid=%d\n",getuid(),getgid());
    printf("euid=%d,egid=%d\n",geteuid(),getegid());

    printf("setuid is %d\n",setuid(1000));

    printf("uid=%d,gid=%d\n",getuid(),getgid());
    printf("euid=%d,egid=%d\n",geteuid(),getegid());

    printf("setuid is %d\n",setuid(1001));
    printf("uid=%d\n",getuid());
    printf("euid=%d\n",geteuid());

}
