#include <stdio.h>
void main(int argc,char *argv[])
{
while(argc-->0)
	{
	//	argv++;
		printf("%s\n",*argv++);
	//	argc--;
	}
}
