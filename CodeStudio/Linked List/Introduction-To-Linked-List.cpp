Ques : https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737

Solution : 
Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node * head = new Node(arr[0]);
    Node * tail=head;
    head->next=NULL;
    if(arr.size()==1)
    {
        return head;
    }
    for(int i=1;i<arr.size();i++)
    {
        Node * temp = new Node(arr[i]);
        temp->next=NULL;
        tail->next = temp;
        tail=temp;
    }
    return head;
}
