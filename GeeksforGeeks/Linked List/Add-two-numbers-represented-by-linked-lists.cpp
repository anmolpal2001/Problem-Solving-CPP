Ques : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Solution : 
// TC : O(max(M,N)) and SC : O(max(M,N))
class Solution
{
    public:
    Node * reverse(Node *head)
    {
        Node * curr=head;
        Node *prev=NULL;
        while(curr!=NULL)
        {
            Node * forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void insertAtTail(struct Node* &ansHead,struct Node* &ansTail,int data)
    {
        Node *temp = new Node(data);
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
    struct Node * add(struct Node* first,struct Node* second)
    {
        int carry = 0;
        Node * ansHead = NULL;
        Node * ansTail = NULL;
        while(first!=NULL || second!=NULL || carry!=0)
        {
            int val1=0;
            if(first!=NULL)
            {
                val1 = first->data;
            }
            int val2=0;
            if(second!=NULL)
            {
                val2 = second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            if(first!=NULL)
            {
                first=first->next;
            }
            if(second!=NULL)
            {
                second=second->next; 
            }
        }
        return ansHead;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node * ans = add(first,second);
        ans = reverse(ans);
        return ans;
    }
};
