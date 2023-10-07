Ques : https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557

Solution : 
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
Node *addOne(Node *head)
{
    head = reverse(head);
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 1;
    while (head != NULL || carry != 0) {
        int val = carry;
        if (head != NULL) {
            val += head->data;
            head = head->next;
        }
        int digit = val % 10;
        carry = val / 10;
        Node *temp = new Node(digit);
        if (ansHead == NULL) {
            ansHead = temp;
            ansTail = temp;
        } else {
            ansTail->next = temp;
            ansTail = temp;
        }
    }
    ansHead = reverse(ansHead);
    return ansHead;
}
