#include <stdio.h>
#include <pwd.h>

int main() {
	struct passwd *ptr;
	ptr=getpwnam("gg");
	
	if(ptr==NULL){
		printf("getpwname false\n");
		return -1;
	}

	printf("name is %s,uid is %d\n",ptr->pw_name,ptr->pw_uid);

}
