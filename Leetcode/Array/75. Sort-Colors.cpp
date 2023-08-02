Ques : https://leetcode.com/problems/sort-colors/

// This problem is a variation of Dutch National Flag Algorithm

Solution 1 : 
// TC : O(N) and SC : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};


Solution 2 : 
// Time Complexity : O(n) and Space Complexity : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;
        while(mid<=hi)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[mid++],nums[lo++]);
                break;
                case 1: mid++;
                break;
                case 2: swap(nums[mid],nums[hi--]);
                break;
            }
        }
    }
};
