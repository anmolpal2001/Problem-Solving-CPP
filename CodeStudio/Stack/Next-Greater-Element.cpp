Ques : https://www.codingninjas.com/studio/problems/next-greater-element_670312

Solution : 
#include <bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	 stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(!st.empty() && st.top()<=curr)
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(curr);
    }
    return ans;
}
