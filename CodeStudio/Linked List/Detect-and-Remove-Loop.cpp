Ques : https://www.codingninjas.com/studio/problems/interview-shuriken-42-detect-and-remove-loop_241049

Solution : 
Node *flyodDetectLoop(Node *head)
{
    if(head==NULL || head->next==NULL)
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

Node *getStartingNode(Node *head)
{
    if(head==NULL || head->next==NULL)
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

Node *removeLoop(Node *head)
{   
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node * startNode = getStartingNode(head);
    if(startNode == NULL)
    {
        return head;
    }
    Node * temp = startNode;
    while(temp->next!=startNode)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
