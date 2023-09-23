Ques : https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897

Solution : 
// Approach 1 : Iterative Solution
// TC : O(N)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    while(curr!=NULL)
    {
        LinkedListNode<int>* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Approach 2 : Recursive Method - 1
// TC : O(N) and SC : O(N)
void reverseNode(LinkedListNode<int>*&head,LinkedListNode<int>*curr,LinkedListNode<int>*prev)
{
    if(curr==NULL)
    {
        head = prev;
        return ;
    }
    LinkedListNode<int> * forward = curr->next;
    reverseNode(head,forward,curr);
    curr->next=prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
  LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverseNode(head, curr, prev);
    return head;
}


// Approach 3 : Recursive Method - 2
// TC : O(N) and SC : O(N)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    LinkedListNode<int>* lastHead = reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return lastHead;
}
