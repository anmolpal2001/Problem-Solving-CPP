Ques : https://www.codingninjas.com/studio/problems/selling-stock_630282

Solution : 
// Memoization Method
// TC : O(N) and SC : O(N)+O(N)
long memoSol(int ind,int buy,long *values,int n,vector<vector<long>>&dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit = 0;
    if(buy)
    {
        profit = max(-values[ind] + memoSol(ind+1, 0, values,n,dp), 0 + memoSol(ind+1, 1, values, n,dp));
    }
    else
    {
        profit = max(values[ind]+memoSol(ind+1,1,values,n,dp), 0 + memoSol(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n,vector<long>(2,-1));
    return memoSol(0,1,values,n,dp);
}

// Tabulation Method
// TC : O(N) and SC : O(N)
long tabSol(int n,long *values)
{
    vector<vector<long>>dp(n+1,vector<long>(2,0));
    dp[0][1]=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)
            {
                profit = max(-values[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else
            {
                profit = max(values[ind]+dp[ind+1][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
long getMaximumProfit(long *values, int n)
{
    return tabSol(n,values);
}


// Space Optimized Method - 1
// TC : O(N) and SC : O(1)
long optiSol(int n,long *values)
{
    long currNotBuy,currBuy,nextNotBuy,nextBuy;
    currBuy=currNotBuy=0;    
    for(int i=n-1;i>=0;i--)
    {
        nextNotBuy = max(values[i]+currBuy,0 + currNotBuy);
        nextBuy =  max(-values[i] + currNotBuy, 0 + currBuy);
        currBuy=nextBuy;
        currNotBuy=nextNotBuy;
    }
    return currBuy;
}
long getMaximumProfit(long *values, int n)
{
    return optiSol(n,values);
}


// Recursive Solution - not the best
// TC : O(N) and SC : O(N) -> recursive stack space
long recursSol(int ind,int buy,long *values,int n)
{
    if(ind==n)
        return 0;
    long profit = 0;
    if(buy)
    {
        profit = max(-values[ind] + recursSol(ind+1, 0, values,n), 0 + recursSol(ind+1, 1, values, n));
    }
    else
    {
        profit = max(values[ind]+recursSol(ind+1,1, values,n), 0 + recursSol(ind+1,0,values,n));
    }
    return profit;
}
long getMaximumProfit(long *values, int n)
{
    return recursSol(0,1,values,n);
}
