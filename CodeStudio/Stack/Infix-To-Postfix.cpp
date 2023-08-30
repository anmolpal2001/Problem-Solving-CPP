Ques : https://www.codingninjas.com/studio/problems/day-23-:-infix-to-postfix-_1382146

Solution : 
// SC : O(N) and TC : O(N)
#include<stack>
int preced(char op)
{
	if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string exp){
	stack<char> st;
	string postfix = "";
	for( char ch:exp)
	{
		if(isalnum(ch))
		{
			postfix+=ch;
		}
		else if(ch=='(')
		{
			st.push(ch);
		}
		else if(ch==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				postfix += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while(!st.empty() && preced(ch) <= preced(st.top()))
			{
				postfix += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	while(!st.empty())
	{
		postfix += st.top();
		st.pop();
	}
	return postfix;
}
