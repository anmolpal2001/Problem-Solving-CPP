Ques : https://www.codingninjas.com/studio/problems/insert-at-end-of-doubly-linked-list_8160464

Solution : 
Node * insertAtTail(Node *head, int k) {
    if(head==NULL)
    {
        Node *temp=new Node(k);
        head=temp;
    }
    else
    {
        Node *temp=new Node(k);
        Node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        temp->prev=curr;
        curr->next=temp;
    }
    return head;
}
