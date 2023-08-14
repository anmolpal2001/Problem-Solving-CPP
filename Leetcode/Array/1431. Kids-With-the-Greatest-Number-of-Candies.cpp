Ques : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for (int candy : candies) 
        {
            maxCandies = max(maxCandies, candy);
        }

        vector<bool> result;
        for (int candy : candies) 
        {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        return result;
    }
};
