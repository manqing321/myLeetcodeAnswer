#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

int main(int argc, char *argv[]) {

	//prepare for ListNode
	struct ListNode a;
	a.val=7;
	a.next=NULL;
	struct ListNode s;
	s.val=5;
	s.next=&a;
	struct ListNode d;
	d.val=3;
	d.next=&s;
	struct ListNode headA;
	headA.val=1;
	headA.next=&d;


	struct ListNode q;
	q.val=4;
	q.next=NULL;
	struct ListNode headB;
	headB.val=2;
	headB.next=&q;


	struct ListNode* arr=(struct ListNode*)malloc(3*sizeof(struct ListNode));
	int i;
	for(i=0; i<3; i++) {
		arr[i].val=100*(1+i);
	}
	arr[0].next=&arr[1];
	arr[1].next=&arr[2];
	arr[2].next=NULL;
	a.next=arr;
	q.next=arr;
	//printf("1");
	struct ListNode* result=getIntersectionNode(&headA,&headB);

	printf("\nthe answer is %d",result->val);

	free(arr);

	return 0;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//遍历时间 A B两个指针 第一遍到各自的结尾时，指向对方的头节点
	//同时为NULL就返回NULL
	if(NULL==headA||NULL==headB)
		return NULL;
	struct ListNode *pa=headA;
	struct ListNode *pb=headB;
	//printf("headA:%x headB:%x\n",headA,headB);
	while(!(NULL==pa && NULL==pb)) {
		printf("%d %d\n",pa->val,pb->val);
		if(pa==pb)
			return pa;
		else if(NULL==pa->next && NULL!=pb->next) {
			//printf("headA:%x headB:%x\n",headA,headB);
			pa=headB;
			pb=pb->next;
		} else if(NULL==pb->next && NULL!=pa->next) {
			//printf("headA:%x headB:%x\n",headA,headB);
			pb=headA;
			pa=pa->next;
		} else {
			pa=pa->next;
			pb=pb->next;
		}

	}
	//printf("4");
	return 0;

}







