#include "../apue.h"

int main(int argc, char *argv[]) {
	if (argc!=2) {
		printf("usage: filename\n");
		return 0;
	}

	struct stat buf;
	if( stat(argv[1],&buf) <0 ) {
		printf("stat error\n");
		return 0;
	}
	if( S_ISUID&buf.st_mode ){
	printf("%s has set uid,value is %d\n",argv[1],S_ISUID&buf.st_mode);
	} else {

		printf("%s has no set uid\n",argv[1]);
		/*
		if( chmod(argv[1],buf.st_mode | S_ISUID) <0 ) {
			printf("chmod error\n");
			return 0;
		}
		printf("no setuid,but we set it\n");
		*/
	}

	return 0;

}
