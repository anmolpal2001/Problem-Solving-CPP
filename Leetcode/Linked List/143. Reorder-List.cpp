Ques : https://leetcode.com/problems/reorder-list/

Solution : 
// Without Stack
class Solution {
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL)
        {
            ListNode *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        ListNode *h1=head;
        ListNode *mid=getMiddle(head);
        ListNode *h2=reverse(mid->next);
        mid->next=NULL;
        ListNode *next1=h1->next;
        ListNode *next2=h2->next;
        while(h1!=NULL && h2!=NULL)
        {
            next1=h1->next;
            next2=h2->next;
            h1->next=h2;
            h2->next=next1;
            h1=next1;
            h2=next2;
        }
    }
};

// With Stack
class Solution {
public:
    void reorderList(ListNode* head) {
       int size = 0;
        ListNode* curr = head;
        stack <ListNode*> nodes;
        while (curr != NULL) {
            nodes.push(curr);
            size++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < size / 2; i++) {
            ListNode* temp = curr->next;
            curr->next = nodes.top();
            nodes.pop();
            curr = curr->next;
            curr->next = temp;
            curr = temp;
        }
        curr->next = NULL;
    }
};
