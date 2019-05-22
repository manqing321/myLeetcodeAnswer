struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    int distance=0;
    int len=0;
    while(fast!=NULL)
    {
        len+=1;
        fast=fast->next;
        if(distance<n+1)
        {
            distance+=1;
        }else
        {
            slow=slow->next;
        }
    }
    if(len==n)
    {
        if(len==1)
            return NULL;
        else{
            struct ListNode* tmp=head->next; 
            free(head);
            return tmp;
        }
    }
    struct ListNode* dst=slow->next;    
    //printf("??%d",slow->val);
    slow->next=slow->next->next;
    free(dst);
    return head;
}


