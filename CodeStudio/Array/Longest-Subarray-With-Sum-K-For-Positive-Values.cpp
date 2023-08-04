Ques : https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399

Solution : 
// TC : O(N) and O(1)   but in worst case TC : O(2N)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum=a[0];
    int maxLen=0;
    int left=0,right=0;
    int n=a.size();
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=a[left];
            left++;
        }
        if(sum==k)
        {
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=a[right];
        }
    }
    return maxLen;
}
