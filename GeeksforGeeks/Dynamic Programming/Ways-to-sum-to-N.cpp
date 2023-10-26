Ques : https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n5759/1

Solution : 
// TC : O(N*m) and SC : O(N)
class Solution
{
  public:
    int mod=1e9+7;
    int helper(int arr[],int m,int N,vector<int>&dp)
    {
        if(N==0)
        {
            return 1;
        }
        if(N<0)
        {
            return 0;
        }
        int ans=0;
        if(dp[N]!=-1)
            return dp[N];
        for(int i=0;i<=m;i++)
        {
            ans= (ans + helper(arr,m,N-arr[i],dp))%mod;
        }
        return dp[N]=ans;
    }
    int countWays(int arr[], int m, int N) 
    { 
        vector<int> dp(N+1,-1);
        return helper(arr, m-1, N, dp);
    } 
    
};
