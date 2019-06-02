/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void Change(struct ListNode *pointer);
struct ListNode *swapPairs(struct ListNode* head){
    if(NULL==head)
        return NULL;
    if(NULL==head->next)
        return head;        
    struct ListNode *newHead=head->next;
    head->next=newHead->next;
    newHead->next=head;
    Change(head);    
    return newHead;    
}

/*
** ���������Ľڵ�
*/
void Change(struct ListNode *pointer)
{
    //���������������ڵ�
    struct ListNode *first;
    struct ListNode *second;
    struct ListNode *thrid;
    if(NULL==pointer)
        return;
    first=pointer->next;
    if(NULL==first)
        return;
    second=first->next;
    if(NULL==second)
        return;
    thrid=second->next;
    pointer->next=second;
    second->next=first;
    first->next=thrid;
    Change(first);
}

