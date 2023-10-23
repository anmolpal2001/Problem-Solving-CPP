Ques : https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

Solution : 
// Memoization Method
// TC : O(N) and SC : O(N)+O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007
int memo(int nStairs, vector<int>& dp) {
    if (nStairs == 0 || nStairs == 1) {
        dp[nStairs] = 1;
    }
    if (dp[nStairs] != -1) {
        return dp[nStairs];
    }
    
    dp[nStairs] = (memo(nStairs - 1, dp) + memo(nStairs - 2, dp))%MOD;
    return dp[nStairs];
}
int countDistinctWays(int nStairs) {    
    vector<int>dp(nStairs+1,-1);
    return memo(nStairs,dp);
}

// Tabulation Method
// TC : O(N) and SC : O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007
int tabul(int nStairs)
{
    vector<int>dp(nStairs+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=nStairs;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }   
    return dp[nStairs];
}
int countDistinctWays(int nStairs) {    
    return tabul(nStairs);
}


// Space Optimized Method
// TC : O(N) and SC : O(1)
#include <bits/stdc++.h> 
#define MOD 1000000007
int solve(int nStairs)
{
    int prev2=1;
    int prev1=1;
    for(int i=2;i<=nStairs;i++)
    {
        int curr = (prev2 + prev1)%MOD;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int countDistinctWays(int nStairs) {  
    return solve(nStairs);
}


// Recursive Solution - not the best
// TC : O(N) and SC : O(N) -> recursive stack space
#include <bits/stdc++.h> 
#define MOD 1000000007
int helper(int i,int nStairs)
{
    if(i==nStairs)
        return 1;
    if(i>nStairs)
        return 0;
    return (helper(i+1,nStairs) + helper(i+2,nStairs));
}
int countDistinctWays(int nStairs) {  
    return helper(0,nStairs);
}
