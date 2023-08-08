Ques : https://leetcode.com/problems/next-greater-element-i/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums1.size(),-1);
        unordered_map<int,int> mp;
        int m=nums2.size();

        for(int i=m-1;i>=0;i--)
        {
            int curr=nums2[i];
            while(!st.empty() && st.top()<=curr)
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
                mp[nums2[i]]=st.top();
            }
            st.push(curr);
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(nums1[i]) != mp.end())
            {
                ans[i]=mp[nums1[i]];
            }
        }
        return ans;
    }
};
