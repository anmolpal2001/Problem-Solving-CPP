Ques : https://www.codingninjas.com/studio/problems/insert-node-at-the-beginning_8144739

Solution : 
Node* insertAtFirst(Node* list, int newValue) {
    Node * temp=new Node(newValue);
    temp->next=list;
    list=temp;
}
