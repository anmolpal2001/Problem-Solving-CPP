Ques : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Solution : 
// Space Optimized Method - 2
// TC : O(N) and SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit=0;
                if(buy)
                {
                    int buyStock = -prices[ind] + next[0];
                    int skipStock = 0 + next[1];
                    profit = max(buyStock,skipStock);
                }
                else
                {
                    int sellStock = prices[ind]+next[1];
                    int skipStock = 0 + next[0];
                    profit = max(sellStock,skipStock);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};
