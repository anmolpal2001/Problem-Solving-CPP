Ques : https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250

Solution : 
// Approach - 1
// TC : O(N) and SC : O(1)
int getLength(Node * head)
{
    int len = 0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len = getLength(head);
    int mid = (len/2);
    Node * temp = head;
    int cnt=0;
    while(cnt<mid)
    {
        cnt++;
        temp=temp->next;
    }
    return temp;
}


// Approach - 2
// TC : O(N/2) and SC : O(1)
Node *findMiddle(Node *head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
