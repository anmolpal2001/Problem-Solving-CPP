Ques : https://www.codingninjas.com/studio/problems/-intersection-of-two-linked-lists_630457

Solution : 
// TC : O(2M) and SC : O(1)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead ==NULL || secondHead ==NULL)
    {
        return NULL;
    }
    Node *a = firstHead;
    Node *b = secondHead;
    while(a!=b)
    {
        a=a==NULL ? secondHead : a->next;
        b=b==NULL ? firstHead : b->next;
    }
    return a;
}
