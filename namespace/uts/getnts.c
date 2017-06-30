#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	struct utsname uts;
	if(uname(&uts)==-1) {
		fprintf(stderr, "uname faile\n");
		return -1;
	}
	printf("uts is %s\n",uts.nodename );
	return 0;
}
