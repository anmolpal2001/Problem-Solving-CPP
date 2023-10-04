Ques : https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644

Solution : 

Node* kReverse(Node* head, int k) {
    //baseCase
    if(head==NULL)
    {
        return NULL;
    }
    Node * curr = head;
    int count = 0;
    while(curr!=NULL && count<k)
    {
        curr=curr->next;
        count++;
    }
     if (count == k) {
        curr = kReverse(curr, k);
        while (count > 0) {
            Node* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
            count--;
        }
        head = curr;
    }
    return head;
}
