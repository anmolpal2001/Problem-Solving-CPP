Ques : https://leetcode.com/problems/contains-duplicate/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                return true;
            }
            else
            {
                mpp[nums[i]]++;
            }
        }
        return false;
    }
};
