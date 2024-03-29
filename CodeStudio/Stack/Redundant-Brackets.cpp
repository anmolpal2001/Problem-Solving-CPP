Ques : https://www.codingninjas.com/studio/problems/redundant-brackets_975473

Solution : 
// TC : O(N) and SC : O(N)
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) 
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            if(ch==')')
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top=='+' || top=='*' || top=='-' || top=='/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true) 
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;

}
