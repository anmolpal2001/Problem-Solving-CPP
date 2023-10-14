Ques : https://leetcode.com/problems/combination-sum-ii/

Solution : 
// TC : O(2^N * k) and SC : O(k * x)
class Solution {
public:
    void helper(int ind,int target,vector<vector<int>>&ans,vector<int>&output,vector<int>arr)
    {
        if(target==0)
        {
            ans.push_back(output);
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) return;
            output.push_back(arr[i]);
            helper(i+1,target-arr[i],ans,output,arr);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>output;
        helper(0,target,ans,output,candidates);
        return ans;
    }
};
