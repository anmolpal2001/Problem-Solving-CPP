Ques : https://leetcode.com/problems/combination-sum/

Solution : 
// TC : O(2^t*k) and SC : O(k*x) where k is avg length & x is no. of combinations
class Solution {
public:
    void helper(int ind,vector<int>arr,vector<int>&output,vector<vector<int>>&ans,int target)
    {
        if(ind==arr.size())
        {
            if(target==0)
                ans.push_back(output);
            return;
        }
        if(arr[ind]<=target)
        {
            output.push_back(arr[ind]);
            target=target-arr[ind];
            helper(ind,arr,output,ans,target);
            target=target+arr[ind];
            output.pop_back();
        }
        helper(ind+1,arr,output,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        helper(0,candidates,output,ans,target);
        return ans;
    }
};
