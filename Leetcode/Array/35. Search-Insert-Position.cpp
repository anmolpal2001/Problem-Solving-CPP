Ques : https://leetcode.com/problems/search-insert-position/

Solution : 
// TC : O(logN) and SC : O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        if(target>nums[end])
            return end+1;
        while(start<end)
        {
            int mid=start + (end-start)/2;
            if(nums[mid]>=target)
            {
                end = mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
};
