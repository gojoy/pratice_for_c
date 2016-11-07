#include <stdio.h>
#include <assert.h>
void out(){
	printf("in out func\n");
	//exit(0);
}

int use(int n){
	printf("in use\n");
	if (n>0)
	{
		out();
		/* code */
	}else{
		return 1;
	}
}

int as(int n){
	printf("begin as\n");
	assert(n!=0);
	printf("input n is %d\n",n );
    return 0;

}
void main(int argc, char const *argv[])
{
	/* code */
	//printf("use is %d\n",use(2) );
	as(0);
}
