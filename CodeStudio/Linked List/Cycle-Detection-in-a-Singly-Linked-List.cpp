Ques : https://www.codingninjas.com/studio/problems/cycle-detection-in-a-singly-linked-list_628974

Solution : 
// Approach - 1
// TC : O(N) and SC : O(N)
bool detectCycle(Node *head)
{
	if(head==NULL)
    {
        return true;
    }
    map<Node*,bool> visited;
    Node *temp = head;
    while (temp!=NULL)
    {
        if(visited[temp]==true)
        {
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

// Approach - 2
// TC : O(N) and SC : O(1)
bool detectCycle(Node *head)
{
    if(head==NULL || head->next==NULL)
        {
            return false;
        }
        Node *slow=head;
        Node *fast=head;
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
}
