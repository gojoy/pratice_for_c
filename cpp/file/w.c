#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	char buf[]="create by gg";
	
	umask(007);
	if ((fd=open("x",O_WRONLY|O_CREAT|O_TRUNC,0624))<0){
		printf("creat failed\n");
		return -1;
	}
	if (access("x",R_OK)<0)
	{
		printf("cannot read\n");
		return -1;
	}else{
		printf("reeay to open\n");
	}
	if (write(fd,buf,10)!=10){
		printf("write faild\n");
		return -1;
	}

	return 0;
}
