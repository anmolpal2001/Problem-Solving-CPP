Ques : https://www.codingninjas.com/studio/problems/search-in-a-linked-list_975381

Solution : 
int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>*curr=head;
    while(curr!=NULL)
    {
        if(curr->data==k)
        {
            return 1;
        }
        curr=curr->next;
    }
    return 0;
}
