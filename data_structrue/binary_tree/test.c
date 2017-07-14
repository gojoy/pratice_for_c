#include "btr.h"

int main() {

	printf("begin\n");

	Tree T;
	T=createTree(5);
	show(T);
	inserttree(T,3);
	show(T);
	inserttree(T,7);
	show(T);
	inserttree(T,4);
	inserttree(T,6);
	inserttree(T,2);
	inserttree(T,8);
	inserttree(T,9);
	inserttree(T,1);
	inserttree(T,11);
	show(T);
	//deletet(T,7);
	//deletet(T,3);
	//printf("after delete\n");
	show(T);
	printf("printtree\n");
	printbtr(T);
	printf("macro\n");
	printf("getelem is %d\n",getelem(T));

}
