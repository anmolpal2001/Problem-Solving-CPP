Ques : https://www.codingninjas.com/studio/problems/frog-jump_3621012

Solution : 
// Memoization Method
// TC : O(N) and SC : O(N)+O(N)
int memoSol(int n,vector<int>heights,vector<int>&dp)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int left=solve(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right=solve(n-2, heights, dp) + abs(heights[n]-heights[n-2]);
    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return memoSol(n-1, heights,dp);
}

// Tabulation Method
// TC : O(N) and SC : O(N)
int tabSol(int n,vector<int>&heights)
{
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
        {
            right = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(left,right);
    }
    return dp[n-1];
}
int frogJump(int n, vector<int> &heights)
{
   return tabSol(n, heights);
}


// Space Optimized Method
// TC : O(N) and SC : O(1)
int optiSol(int n,vector<int>&heights)
{
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++)
    {
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
        {
            right = prev2 + abs(heights[i]-heights[i-2]);
        }
        int curr = min(left,right);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
   return optiSol(n, heights);
}


// Recursive Solution - not the best
// TC : O(N) and SC : O(N) -> recursive stack space
int recursSol(int ind,vector<int>&heights)
{
    if(ind==0)
        return 0;
    int left = recursSol(ind-1, heights) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1) right = recursSol(ind-2,heights) + abs(heights[ind]-heights[ind-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
   return recursSol(n-1, heights);
}
