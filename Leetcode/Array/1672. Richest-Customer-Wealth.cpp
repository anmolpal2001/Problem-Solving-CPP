Ques : https://leetcode.com/problems/richest-customer-wealth/

Solution : 
// TC : O(m*n) and SC : O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int maxWealth = 0;
        for (const auto& customer : accounts) 
        {
            int wealth = 0;
            for (int account : customer) {
                wealth += account;
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
