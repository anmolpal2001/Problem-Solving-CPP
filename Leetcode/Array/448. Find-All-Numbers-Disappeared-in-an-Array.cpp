Ques : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
