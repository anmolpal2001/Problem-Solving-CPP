Ques : https://www.codingninjas.com/studio/problems/delete-last-node-of-a-doubly-linked-list_8160469

Solution : 
Node * deleteLastNode(Node *head) {
    if(head->next==NULL)
    {
        Node *temp=head;
        head=NULL;
        delete temp;
    }
    else
    {
        Node *curr=head;
        Node *prev=NULL;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete curr;
    }
    return head;
}
