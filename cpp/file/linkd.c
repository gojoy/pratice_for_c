#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int slink()
{
	if (link(".","lnx")<0)
	{
		printf("link faild\n");
	}
	return 0;
}

int creatsy(){
	if (symlink("x","x_sy")<0)
	{
		printf("slink faild\n");
        return -1;
	}
    return 0;
}
int sunlink(){
	if(unlink("lnx")<0)
		printf("unlink faild\n");
	return 0;
}
int main(int argc, char const *argv[])
{
	//slink();
	//sunlink();
	creatsy();
	return 0;
}
