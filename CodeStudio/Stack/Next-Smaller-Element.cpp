Ques : https://www.codingninjas.com/studio/problems/next-smaller-element_1112581

Solution : 
// TC : O(N) and SC : O(N)
#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(st.top()>=curr)
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
