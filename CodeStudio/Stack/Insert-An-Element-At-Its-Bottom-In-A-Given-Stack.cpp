Ques : https://www.codingninjas.com/studio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

Solution : 
// TC : O(N) and SC : O(N)
#include <bits/stdc++.h> 
void solve(stack<int>& st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int num=st.top();
    st.pop();
    solve(st,x);
    st.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
