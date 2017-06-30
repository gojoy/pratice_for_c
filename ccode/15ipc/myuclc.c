#include "apue.h"
#include <ctype.h>

int main(){
	int c;

	while((c=getchar())!=EOF){
		if(isupper(c))
			c=tolower(c);
		if(putchar(c)==EOF){
			printf("output error\n");
			return -1;
		}
		if(c=='\n')
			fflush(stdout);
	}
	return 0;
}

