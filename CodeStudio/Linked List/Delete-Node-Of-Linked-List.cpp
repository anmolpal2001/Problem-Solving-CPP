Ques : https://www.codingninjas.com/studio/problems/delete-node-of-linked-list_8160463

Solution : 
Node *deleteLast(Node *list){
    Node*curr=list;
    Node* prev=NULL;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    delete curr;
    return list;
}
