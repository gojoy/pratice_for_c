#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define W 2

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	printf("begin\n");
	if ((pid=fork())<0)
	{
		printf("fork error\n");
		exit(7);
		/* code */
	}else if (pid==0)
	{
		pid_t child=getpid();
		printf("in child process pid %d\n",child);
		sleep(20);
		printf("after sleep\n");
		//abort();
		exit(11);
	}else{
		pid_t parent=getpid();
		printf("in parents process pid is %d\n",parent);
#if W==1
		if((wait(&status))!=pid)
			printf("wait faild\n");
		printf("wait %d sucess,status is %d\n",pid,status);
		if(WIFEXITED(status))
			printf("normal exit\n");
#endif
		sleep(100);
		printf("parents end\n");
	}
	return 0;
}
