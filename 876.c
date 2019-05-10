#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head);
int main(int argc, char *argv[]) {
	printf("pls entry your linkNode.val(end by -1) :");
	int i;
	scanf("%d",&i);
	struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=i;
	head->next=NULL;
	if(-1==head->val) {
		printf("your ListNode is -1. ");
		return 0;
	}
	struct ListNode* last;
	last=head;
	while(scanf("%d",&i)) {
		if(-1==i)
			break;
		struct ListNode* p=(struct ListNode*)malloc(sizeof(struct ListNode));
		p->val=i;
		p->next=NULL;

		while(NULL!=last->next) {
			last=last->next;
		}
		last->next=p;
		last=p;
	}
	printf("your ListNode is:");
	struct ListNode* q;
	for(q=head; q; q=q->next) {
		printf(" %d ",q->val);
	}
	printf("\n");
	//printf("1\n");
	struct ListNode* result=middleNode(head);
	printf("the answer is %d",result->val);
	return 0;
}

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* quick=head;
	struct ListNode* slow=head;
	while(quick && slow)
	{
	    quick=quick->next;
		if(quick)
		 quick=quick->next;
		else break;
	    slow=slow->next;		
	}
	return slow; 
} 
/* 
struct ListNode* middleNode(struct ListNode* head) {
	//printf("2\n");
	struct ListNode* arr[100];
	struct ListNode* p=head;
	int i=0;
	while(NULL!=p) {
		//printf("3\n");
		arr[i]=p;
		p=p->next;
		i++;
	}
	struct ListNode* q;
	if(i%2==0) { //取2无余数，个数为 i+1,中间为 i/2 例如 0 1 2 3 4
		q=arr[i/2];

	} else { //取2有余数 个数为i+1 中间为 i/2+1  例如 0 1 2 3 4 5
		q=arr[i/2+1];
	}
	//printf("4\n");
	//free(p);
	return q;
}
*/ 

