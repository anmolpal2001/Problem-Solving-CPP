// Question : https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto fr:m)
        {
            if(fr.second==2)
            {
                ans.push_back(fr.first);
            }
        }
        return ans;
    }
};
