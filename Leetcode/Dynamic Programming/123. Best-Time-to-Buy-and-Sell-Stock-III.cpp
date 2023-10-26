Ques : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Solution : 
// Space Optimized Method
// TC : O(N) and SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy==1)
                    {
                        curr[buy][cap] = max(-prices[ind]+after[0][cap],0+after[1][cap]);    
                    }
                    else
                    {
                        curr[buy][cap]=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};

// Tabulation Method
// TC : O(N) and SC : O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                if(buy==1)
                {
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);    
                }
                else
                {
                    dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                }
            }
        }
    }
   return dp[0][1][2];
    }
};


// Memoization Method
// TC : O(N) and SC : O(N)+O(N)
class Solution {
public:
    int memoSol(int ind,int buy,int cap,vector<int>prices,vector<vector<vector<int>>> dp)
    {
        if(ind==prices.size() || cap==0)
        {
            return 0;
        }
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        if(buy==1)
        {
            return dp[ind][buy][cap]=max(-prices[ind]+memoSol(ind+1,0,cap,prices,dp),0+memoSol(ind+1,1,cap,prices,dp));
        }
        else
        {
            return dp[ind][buy][cap]=max(prices[ind]+memoSol(ind+1,1,cap-1,prices,dp),0+memoSol(ind+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return memoSol(0,1,2,prices,dp);
    }
};


// Recursive Solution - not the best
// TC : O(N) and SC : O(N) -> recursive stack space
class Solution {
public:
    int recursSol(int ind,int buy,int cap,vector<int>prices)
    {
        if(ind==prices.size() || cap==0)
        {
            return 0;
        }
        if(buy==1)
        {
            return max(-prices[ind]+recursSol(ind+1,0,cap,prices),0+recursSol(ind+1,1,cap,prices));
        }
        else
        {
            return max(prices[ind]+recursSol(ind+1,1,cap-1,prices),0+recursSol(ind+1,0,cap,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        return recursSol(0,1,2,prices);
    }
};
