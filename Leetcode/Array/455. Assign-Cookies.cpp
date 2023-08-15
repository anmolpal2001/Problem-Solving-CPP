Ques : https://leetcode.com/problems/assign-cookies/

Solution : 
// TC : O(m * log m + n * log n) and SC : O(1)
class Solution {
public:
    int findContentChildren(vector<int>&g,vector<int>&s) 
    {
        int contentChildren = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIdx = 0, cookieIdx = 0;
        while (childIdx < g.size() && cookieIdx < s.size()) {
            if (s[cookieIdx] >= g[childIdx]) {
                contentChildren++;
                childIdx++;
            }
            cookieIdx++;
        }

        return contentChildren;
        }
};
