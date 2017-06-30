#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if (chown("x",1000,-1)<0)
	{
		printf("chown faild\n");
		return -1;
	}
	return 0;
}
