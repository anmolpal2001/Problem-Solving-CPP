Ques : https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283

Solution : 
Node * uniqueSortedList(Node * head) {
    if(head==NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL)&&(curr->data == curr->next->data))
        {
            Node * next_next = curr->next->next;
            Node * nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}
