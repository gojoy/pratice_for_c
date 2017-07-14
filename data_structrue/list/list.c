#include "list.h"

pList newlist(e el) {

	pList pl;

	pl=(pList)malloc(sizeof(List));
	if(pl==NULL)
		return NULL;

	memset(pl,0,sizeof(List));

	pl->elem=el;

	return pl;
}
	
