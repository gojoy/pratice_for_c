#include "apue.h"

int main(){
	char buf[MAXLINE];
	FILE *p;
	if((p=popen("/root/gg/codeproject/pratice_for_c/cpp/15ipc/utl","r"))==NULL)
		err_sys("popen false");	
	while(1){
		fputs("begin>",stdout);
		fflush(stdout);
		if(fgets(buf,MAXLINE,p)==NULL)
			break;
		if(fputs(buf,stdout)==EOF)
			err_sys("output false");
	}
	if(pclose(p)==-1)
		err_sys("pclose false");
	putchar('\n');
	return 0;
}
