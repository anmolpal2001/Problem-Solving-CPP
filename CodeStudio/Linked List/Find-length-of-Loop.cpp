Ques : https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455

Solution : 
Node *flyodDetectLoop(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node *fast=head;
    Node *slow=head;
    while(slow !=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node *firstNode(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node * intersection = flyodDetectLoop(head);
    if(intersection==NULL)
    {
        return  NULL;
    }
    Node *slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return  slow;
}
int lengthOfLoop(Node *head) {
    if(head==NULL)
    {
        return 0;
    }
    Node * startingNode = firstNode(head);
    if(startingNode==NULL)
    {
        return 0;
    }
    Node *temp=startingNode;
    int count=1;
    while(temp->next!=startingNode)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
