Ques : https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905

Solution : 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head=temp;
        size++;
    }

    void pop()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            int res=head->data;
            Node *temp=head;
            head=head->next;
            delete(temp);
            size--;
        }
    }

    int getTop()
    {
        if(head==NULL)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }
};
