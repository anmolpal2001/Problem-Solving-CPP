Ques : https://leetcode.com/problems/palindrome-linked-list/

Solution :
// Approach - 1
// TC : O(N) and SC : O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(st.top()!=temp->val)
            {
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

// Approach - 2
// TC : O(N) and SC : O(1)
class Solution {
public:
    ListNode * mid (ListNode * head)
    {
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode * reverse(ListNode *head)
    {
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL)
        {
            ListNode*forward = temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        {
            return true;
        }
        ListNode * middle = mid(head);
        middle->next=reverse(middle->next);
        ListNode *temp = middle->next;
        while(temp!=NULL)
        {
            if(head->val != temp->val)
            {
                return false;
            }
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};
