Ques : https://leetcode.com/problems/rearrange-array-elements-by-sign/

Solution : 
// TC : O(N)+O(N/2) and SC : O(N) for returning answer
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int negative=1;
        int positive=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[positive]=nums[i];
                positive+=2;
            }
            else
            {
                ans[negative]=nums[i];
                negative+=2;
            }
        }
        return ans;
    }
};
