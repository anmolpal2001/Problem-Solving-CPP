Ques : https://leetcode.com/problems/intersection-of-two-linked-lists/

Solution : 
// TC : O(2M) and SC : O(1)
class Solution {
public:
    int length(ListNode *head)
    {
        ListNode *temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = length(headA);
        int len2 = length(headB);
        int diff = abs(len1-len2);
        ListNode *curr1=NULL;
        ListNode *curr2=NULL;
        if(len1>len2)
        {
             curr1=headA;
             curr2=headB;
        }
        else 
        {
            curr1=headB;
            curr2=headA;
        }
        while(diff--)
        {
            curr1=curr1->next;
        }
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1==curr2)
            {
                return curr1;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};
