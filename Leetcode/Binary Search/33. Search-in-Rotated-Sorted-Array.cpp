Ques : https://leetcode.com/problems/search-in-rotated-sorted-array/

Solution : 
// TC : O(logn) and SC : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[s]<=nums[mid])
            {
                if(nums[s]<=target && target<nums[mid])
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            else
            {
                if(target<=nums[e] && target>nums[mid])
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
