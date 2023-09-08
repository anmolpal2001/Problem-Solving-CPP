Ques : https://www.codingninjas.com/studio/problems/count-nodes-of-linked-list_5884

Solution : 
int length(Node *head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
