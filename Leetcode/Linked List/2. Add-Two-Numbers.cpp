Ques : https://leetcode.com/problems/add-two-numbers/

Solution : 
// TC : O(max(M,N)) and SC : O(max(M,N))
class Solution {
public:
    void insertAtTail(ListNode* &ansHead, ListNode* &ansTail,int data)
    {
        ListNode *temp = new ListNode(data);
        if(ansHead==NULL)
        {
            ansHead=temp;
            ansTail=temp;
            return;
        }
        else
        {
            ansTail->next=temp;
            ansTail=temp;
        }
    }
    ListNode * add(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode * ansHead = NULL;
        ListNode * ansTail = NULL;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int val1=0;
            if(l1!=NULL)
            {
                val1=l1->val;
            }
            int val2=0;
            if(l2!=NULL)
            {
                val2=l2->val;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        return ansHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = add(l1,l2);
        return ans;
    }
};
