#include "list.h"
#include <stdio.h>

int main() {
	List l;
	l=newList();

	if(isEmpty(l))
		printf("l is empty list\n");

	insertToEnd(l,2);
	showList(l);
	insertToEnd(l,3);
	showList(l);
	insertToEnd(l,4);
	showList(l);

	if(deleteNodeByElem(l,4)==0)
		err_sys("delete false");
	printf("after delete\n");
	showList(l);
	insertToEnd(l,5);
	showList(l);
	reversalList(l);
	printf("reversal list\n");
	showList(l);
	

}
