Ques : https://leetcode.com/problems/next-greater-element-ii/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--)
        {
            int curr=nums[i % n];
            while(!st.empty() && st.top() <=curr)
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                    ans[i]=st.top();
            }
            st.push(curr);
        }
        return ans;
        
    }
};
