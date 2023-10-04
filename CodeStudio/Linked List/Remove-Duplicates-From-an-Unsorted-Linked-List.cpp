Ques : https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331

Solution :
// Approach - 1 
// TC : O(N) and SC : O(N)
Node *removeDuplicates(Node *head)
{
    if(head==NULL)
        return head;
    unordered_set<int> visited;
    Node * curr = head;
    Node *prev=NULL;
    while(curr != NULL){
        if (visited.find(curr->data) != visited.end()){
            Node *next_node = curr->next;
            prev->next = next_node;
            delete curr;
            curr=next_node;
        }
        else{
            visited.insert(curr->data);
            prev=curr;
            curr = curr->next;  
        }
    }
    return head;
}

// Approach - 2 
// TC : O(N^2) and SC : O(1)
Node *removeDuplicates(Node *head)
{
    if(head==NULL)
        return head;
    Node * curr = head;
    Node * temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        Node *prev=curr;
        while(temp!=NULL)
        {
            if(curr->data == temp->data)
            {
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
}
