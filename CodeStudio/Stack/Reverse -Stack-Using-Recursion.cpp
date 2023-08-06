Ques : https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875

Solution : 
// TC : O(N^2) and SC : O(N^2)
void insertAtBottom(stack<int> &stack, int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    insertAtBottom(stack,num);
    stack.push(n);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}
