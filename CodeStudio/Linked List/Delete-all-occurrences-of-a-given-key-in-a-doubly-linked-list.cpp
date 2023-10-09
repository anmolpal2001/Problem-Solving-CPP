Ques : https://www.codingninjas.com/studio/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461

Solution 1 :
Node * deleteAllOccurrences(Node* head, int k) {
    if(head==NULL)
    {
        return NULL;
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==k)
        {
            Node *nodeToDelete = temp;
            if(temp==head)
            {
                head=head->next;
            }
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            if(temp->prev!=NULL)
            {
                temp->prev->next=temp->next;
            }
            
            temp=temp->next;
            delete nodeToDelete;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}

Solution - 2 :
Node * deleteAllOccurrences(Node* head, int k) {
    Node *temp=NULL;
    Node *curr=head;
    while(curr->data==k)
    {
        if(curr->next==NULL)
        {
            return NULL;
        }
        curr=curr->next;
    }
    
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data==k && curr->prev==NULL)
        {
            head=head->next;
            Node *nodeToDelete = curr;
            curr=curr->next;
            temp=curr;
            delete nodeToDelete;
        }
        else if(curr->data==k && curr->next!=NULL)
        {
            temp->next=curr->next;
            curr->next->prev=temp;
            Node *nodeToDelete=curr;
            curr=curr->next;
            delete nodeToDelete;
        }
        else if(curr->data==k && curr->next==NULL)
        {
            temp->next=NULL;
            delete curr;
        }
        temp=curr;
        curr=curr->next;
    }
    return head;
}
