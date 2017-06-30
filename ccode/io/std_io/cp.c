#include <stdio.h>
#define MAX 4

int copybychar();

int main() {
	printf("begin main\n");
	//copybychar();
	//copybyline();
	strcut_io();
}

int copybychar() {
	char c;
	while( (c=getchar())!=EOF) {
		if( putchar(c)==EOF){
			printf("output error\n");
			return 0;;
		}
	}

	if(ferror(stdin)){
		printf("\ninput error\n");
		return 0;
	}

	return 1;

}

int copybyline() {
	char buf[MAX];
	int c=0;
	memset(buf,0,MAX);
	while(fgets(buf,MAX,stdin)!=NULL) {
		c++;
		if(fputs(buf,stdout)==EOF){
			printf("fputs error\n");
			return -1;
		}
	}

	if(ferror(stdin)){
		printf("input error\n");
		return -1;
	}

	return 1;
}

int strcut_io() {

	struct student;
	typedef struct student st;
	struct student {
		int id;
		char name[10];
		st *next;
	};
	st lili;
	lili.id=1;
	//lili.name="123456789";
	char  name[10]="lilixoao";
	sprintf(lili.name,"lili");
	lili.next=NULL;

	printf("begin\n");

	if(fwrite(&lili,sizeof(st),1,stdout)!=1){
		printf("write lili false\n");
		return 0;
	}
	printf("fwrite\n");
	return 1;
}
