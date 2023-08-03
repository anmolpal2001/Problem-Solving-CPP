Ques : https://leetcode.com/problems/merge-strings-alternately/

Solution : 
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i=0,j=0;
        bool flag=false;
        string str;
        while(i<n && j<m)
        {
            if(flag==false)
            {
                str.push_back(word1[i++]);
                flag=true;
            }
            else
            {
                str.push_back(word2[j++]);
                flag=false;
            }
        }
        while(i<n)
        {
            str.push_back(word1[i++]);
        }
        while(j<m)
        {
            str.push_back(word2[j++]);
        }
        return str;
    }
};
