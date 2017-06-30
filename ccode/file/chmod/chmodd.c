#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	struct stat statbuf;
	if(stat("x",&statbuf)<0){
		printf("canot stat the file\n");
		return -1;
	}
	if(chmod("x",statbuf.st_mode|S_ISGID|S_IXGRP|S_IWGRP|S_IRGRP)<0){
		printf("cannot chmod file\n");
		return -1;
	}
	return 0;
}
