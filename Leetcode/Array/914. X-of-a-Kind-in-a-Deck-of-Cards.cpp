Ques : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < deck.size(); i++) 
        {
            mpp[deck[i]]++;
        }
        int gcdVal = mpp.begin()->second;
        for (auto it : mpp) 
        {
            gcdVal = gcd(gcdVal, it.second);
        }
        // return gcdVal >= 2;
        if(gcdVal<2)
        {
            return false;
        }
        return true;
    }
};
