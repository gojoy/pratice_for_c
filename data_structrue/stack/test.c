#include "stack.h"
#include <stdio.h>

int main() {

	stack s;
	int elem;
	elem=0;

	if( (s=createstack())==NULL)
		return 0;

	if(!push(1,s))
		return 0;
	printf("push 1\n");

	if(!push(2,s))
		return 0;
	printf("push 2\n");

	if(!top(s,&elem))
		return 0;

	printf("top is %d\n",elem);

	if(!top(s,&elem))
                return 0;

	printf("top is %d\n",elem);

 	if(!top(s,&elem))
		return 0;

	printf("top is %d\n",elem);



}
