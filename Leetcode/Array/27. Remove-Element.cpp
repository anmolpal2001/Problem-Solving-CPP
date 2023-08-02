Ques : https://leetcode.com/problems/remove-element/

Solution : 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); 
        int j = 0; 
        for(int i = 0; i < n; i++) 
        { 
          if (nums[i] != val) {
                if (i != j) 
                {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
        }
        return j;
    }
};
