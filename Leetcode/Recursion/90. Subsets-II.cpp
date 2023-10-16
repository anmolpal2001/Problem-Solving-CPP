Ques : https://leetcode.com/problems/subsets-ii/

Solution : 
// TC : O(2^n*n) and SC : O(2^n*k)
class Solution {
public:
    void helper(int ind,vector<int>nums,vector<vector<int>>&ans,vector<int>&output)
    {
        // if(ind == nums.size())
        // {
            ans.push_back(output);
        //     return;
        // }
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            helper(i+1,nums,ans,output);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,output);
        return ans;
    }
};
