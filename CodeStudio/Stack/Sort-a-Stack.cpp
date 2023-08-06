Ques : https://www.codingninjas.com/studio/problems/sort-a-stack_985275

Solution :
// TC : O(N^2) and SC : O(N^2)
#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack,int num)
{
	if(stack.empty() || stack.top()<=num)
	{
		stack.push(num);
		return;
	}
	int topE=stack.top();
	stack.pop();
	sortedInsert(stack,num);
	stack.push(topE);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack,num);
}
    
