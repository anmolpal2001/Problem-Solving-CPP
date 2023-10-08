Ques : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Solution -1 : 
class Solution {
public:
    ListNode * reverse(ListNode * head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode *rhead = reverse(head);
        if(n==1)
        {
            ListNode *temp = rhead;
            rhead=rhead->next;
            delete temp;
            reverse(rhead);
        }
        else 
        {
            ListNode *prev=NULL;
            ListNode *curr=rhead;
            int count=1;
            while(count<n)
            {
                prev=curr;
                curr=curr->next;
                count++;
            }
            if(curr->next==NULL)
            {
                ListNode *temp=reverse(rhead);
                head=head->next;
                delete temp;
            }
            else
            {    
                prev->next=curr->next;
                delete curr;
                reverse(rhead);
            }
        }
        return head;
    }
};


Solution -2 : 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        if(len-n==0)
        {
            head=head->next;
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        int count=0;
        while(count<len-n)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        return head;
    }
};
