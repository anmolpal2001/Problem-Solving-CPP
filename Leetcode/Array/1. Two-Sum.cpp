Ques : https://leetcode.com/problems/two-sum/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(target - nums[i])!=s.end()){
                 v.push_back(s[target-nums[i]]);
                 v.push_back(i);
                 return v;
            }
            s[nums[i]]=i;
        }
        return v;
    }
};
