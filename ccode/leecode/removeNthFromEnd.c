#include <stdio.h>

struct ListNode
{
		int val;
		struct ListNode *Next;
				/* data */
};

struct ListNode * removefromend(struct ListNode* head,int n){
	int length=0;
	struct ListNode *p=head;
	while(p!=NULL){
		p=p->next;
		length++;
	}

}


int main(int argc, char const *argv[])
{
		printf("begin\n");
			return 0;
}
