Ques : https://www.codingninjas.com/studio/problems/introduction-to-doubly-linked-list_8160413

Solution : 
Node* constructDLL(vector<int>& arr) {
    Node*head=new Node(arr[0]);
    Node *tail=head;
    for(int i=1;i<arr.size();i++)
    {
        Node *temp=new Node(arr[i]);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
    return head;
}
