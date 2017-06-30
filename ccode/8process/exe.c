#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[]={"USER=unknow","PATH=/tmp",NULL};
int main(int argc, char const *argv[])
{
	pid_t pid;
	if((pid=fork())<0){
		printf("fork error\n");
		return -1;
	}else if(pid==0){
		printf("in cpid\n");
		if(execle("/root/code/cpp/8process/a.out","a.out","echo","sqweecond",(char *)0,env_init)<0){
			printf("ecevle error\n");
			return -1;
		}	
	}
	if (waitpid(pid,NULL,0)<0)
		{
			printf("wait error\n");
			return -1;
			/* code */
		}
		printf("in ppid\n");
	return 0;
}