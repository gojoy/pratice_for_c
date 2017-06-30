#include <stdio.h>
unsigned a=1;
struct{
	unsigned int aa:8;
	unsigned int bb:8;
	unsigned int cc:8;
	unsigned int dd:1;
	unsigned int a1:8;
	}pt;
struct{
	unsigned int aa:1;
	unsigned int bb:1;
	unsigned int cc:1;
	unsigned int dd:1;
	unsigned int ee:4;
	}n;
void main(){
	n.aa=1;
	n.bb=1;
	n.cc=1;
	n.dd=1;
	n.ee=15;
	printf("n is %d\n",n);
	pt.aa=0;
	pt.bb=0;
	pt.cc=0;
	pt.dd=1;
	pt.a1=255;
	printf("pt is %ld\n",pt);
int c=sizeof(a);
int d=sizeof(int);
printf("length of unsigned is %d\n",d);
int lpt=sizeof(pt);
printf("lengtn of pt is %d\n",lpt);
}
