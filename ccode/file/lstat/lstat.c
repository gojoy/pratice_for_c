#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void main(int argc, char const *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	for (i = 0; i < argc; i++)
	{
		printf("i %d is %s:\n",i,argv[i] );
		if (lstat(argv[i],&buf)<0)
		{
			printf("%s lstat wrong\n",argv[i]);
			continue;
		}
		if (S_ISREG(buf.st_mode))
			ptr="regular";
		else if (S_ISDIR(buf.st_mode))
			ptr="directory";
		else if(S_ISCHR(buf.st_mode))
			ptr="character special";
		else if (S_ISFIFO(buf.st_mode))
			ptr="fifo";
		else if (S_ISSOCK(buf.st_mode))
			ptr="scoket";
		else if (S_ISLNK(buf.st_mode))
			ptr="symbolic link";
		else
			ptr="unkown mode";
		printf("%s\n",ptr );
	}
	
}