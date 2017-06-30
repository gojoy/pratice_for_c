#include <stdio.h>

/*
int swap(char &a,char &b){
	char temp;
	temp=a;
	a=b;
	b=temp;
	return 0;
}
*/

int pswap(char *a,char *b){
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	char str[]="zxc";
	char a='a';
	char b='b';
	printf("str is %s,a is %c\n",str,a);
	pswap(str,&b);
	printf("%s\t%c\n",str,b);
	return 0;
}
