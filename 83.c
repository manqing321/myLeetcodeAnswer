#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head);

int main(int argc, char *argv[]) {
	struct ListNode arr[5];
	printf("pls entry five number :");
	scanf("%d %d %d %d %d",&arr[0].val,&arr[1].val,&arr[2].val,&arr[3].val,&arr[4].val);
	printf("\nfour number is :");
	int i;
	for(i=0; i<5; i++) {
		printf(" %d ",arr[i].val);
		if(i<4)
			arr[i].next=&arr[i+1];
		else
		    arr[i].next=NULL; 
	}
	struct ListNode* head=&arr[0];
	struct ListNode* p=deleteDuplicates(head);
	printf("\nafter this func:");
	while(NULL!=p) {
		printf("  %d",p->val);
		p=p->next;		
	}
	printf("\n");
	return 0;
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *p=head;
	while(NULL!=p && NULL!=p->next) {
		while(NULL!=p->next && p->next->val==p->val)
			p->next=p->next->next;
		p=p->next;
	}
	return head;
}
