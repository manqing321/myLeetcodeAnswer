/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1->val==0 && l1->next==NULL)
		return l2;
	else if(l2->val==0 && l2->next==NULL)
		return l1;
	
    struct ListNode* head;
	struct ListNode* pre;
    struct ListNode* left=l1;
    struct ListNode* right=l2;
    int isAdd;
	
	isAdd=0;
	head=NULL;
	pre=NULL;
	
    while(left!=NULL || right!=NULL)
    {     
		struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next=NULL;
		if(NULL==head)
			head=p;	
		if(NULL!=pre)
			pre->next=p;
		if(left!=NULL && right!=NULL)
		{
			p->val=left->val+right->val;
			left=left->next;
			right=right->next;
		}else if(left!=NULL)
		{
			p->val=left->val;
			left=left->next;
		}else{
			p->val=right->val;
			right=right->next;
		}
		
        if(isAdd==1){
            p->val++;
            isAdd=0;
        }
        if(p->val>9)
        {
            p->val-=10;
            isAdd=1;
        }
		pre=p;        
    }
    
    if(isAdd==1)
    {
        struct ListNode *tmp=(struct ListNode*)malloc(sizeof(struct ListNode));        
        tmp->next=NULL;
        tmp->val=1;
        pre->next=tmp;
    }
    return head;    
}

