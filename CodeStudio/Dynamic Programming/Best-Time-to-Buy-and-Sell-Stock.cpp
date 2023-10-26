Ques : https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405

Solution : 
// TC : O(N) and SC : O(1)
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=prices[0];
    int maxProfit=0;
    for(int i=1;i<prices.size();i++)
    {
        int cost = prices[i]-mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,prices[i]);
    }
    return maxProfit;
}
