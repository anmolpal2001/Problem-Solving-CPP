Ques : https://leetcode.com/problems/missing-number/

Solution : 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0,xor2=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            xor1^=i;
            xor2^=nums[i];
        }
        xor1=xor1^n;
        return (xor1^xor2);
    }
};
