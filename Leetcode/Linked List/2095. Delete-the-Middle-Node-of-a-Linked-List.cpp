Ques : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

Solution : 
class Solution {
public:
    ListNode * getMiddle(ListNode * head)
    {
        ListNode * fast=head;
        ListNode * slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next;
            if(fast->next!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode * middle = getMiddle(head);
        ListNode *temp = head;
        while(temp->next!=middle)
        {
            temp=temp->next;
        }
        temp->next=middle->next;
        delete middle;
        return head;
    }
};
