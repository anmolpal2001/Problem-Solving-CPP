Ques : https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505

Solution : 
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int sum=0;
    int n=nums.size();
    int maxLen = 0;
    map<int,int> preSum;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==k)
        {
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;
        if(preSum.find(rem)!=preSum.end())
        {
            int len=i-preSum[rem];
            maxLen=max(maxLen,len);
        }
        if(preSum.find(sum)==preSum.end())
        {
            preSum[sum]=i;
        }
    }
    return maxLen;
}
