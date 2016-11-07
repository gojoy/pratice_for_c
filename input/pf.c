#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t fp;
	int c=0;
	fp=fork();
	if(fp<0)	printf("error/n");
	else if (fp==0){
	printf("child,pid is %d\n",getpid());
	}
	else{
	printf("parent,pid is %d\n",getpid());
	}
	//printf("fp=%d\n",fp);
	return 0;
}
