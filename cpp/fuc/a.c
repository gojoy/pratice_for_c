#include <stdio.h>
int a;
int f(a)
{
a=a+1;
return a;
}
void main()
{
int b=2;
printf("b=%d\n",b);
printf("f(b)=%d",f(b));
printf("b=%d\n",b);

}
