Ques : https://leetcode.com/problems/jump-game/

Solution : 
// TC : O(N) and SC : O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (i > maxReachable) 
            {
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= nums.size() - 1) 
            {
                return true;
            }
        }
        return true;
    }
};
