Ques : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Solution : 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        while(j<n)
        {
            if(nums[i]==nums[j])
                j++;
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};