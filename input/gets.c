#include <stdio.h>
#include <stdlib.h>
void main(){
char ch;
char cmd[100];
//ch=getchar();
//cmd[0]=ch;
int i=0;
while((ch=getchar())!='#')
{
//ch=getchar();
putchar(ch);
cmd[i++]=ch;
}
int j=0;
printf("this is cmd\n");
while(cmd[j]!='\0')
	{
//printf("this is cmd\n");
	if (cmd[j]=='\n') cmd[j]='0';
	putchar(cmd[j++]);
	}
}
