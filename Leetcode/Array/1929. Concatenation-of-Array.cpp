Ques : https://leetcode.com/problems/concatenation-of-array/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans.insert(ans.end(), nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};
