Ques : https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937

Solution : 
// Approach - 1 
// TC : O(N) and SC : O(1)
Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;
        }
        else if(temp->data == 1)
        {
            oneCount++;
        }
        else if(temp->data == 2)
        {
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(zeroCount!=0)
        {
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0)
        {
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}

// Approach - 2 
// TC : O(N) and SC : O(1)
Node *insertAtTail(Node *&tail,Node *temp)
{
    tail->next=temp;
    tail=temp;
}

Node* sortList(Node *head){
    Node * zeroHead = new Node(-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead;

    Node *temp= head;
    while(temp!=NULL)
    {
        int value = temp->data;
        if(value == 0)
        {
            insertAtTail(zeroTail,temp);
        }
        else if(value == 1)
        {
            insertAtTail(oneTail,temp);
        }
        else if(value == 2)
        {
            insertAtTail(twoTail,temp);
        }
        temp=temp->next;
    }
    if(oneHead->next!=NULL)
    {
        zeroTail->next=oneHead->next;
    }
    else
    {
        zeroTail->next=twoHead->next;
    }
    
    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
