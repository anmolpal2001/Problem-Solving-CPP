Ques : https://practice.geeksforgeeks.org/problems/anagram-1587115620/1

// TC : O(N) and SC : O(1)
Solution - 1 :
class Solution
{
    public:
    bool isAnagram(string a, string b){
        if(a.length()!=b.length())
            return false;
        map<char,int> st1;
        for(int i=0;i<a.length();i++)
        {
            st1[a[i]]++;
        }
        for(int i=0;i<b.length();i++)
        {
            if (st1.find(b[i]) == st1.end() || st1[b[i]] == 0) {
                return false;
            }
            st1[b[i]]--;
        }
        return true;
    }

};


Solution - 2 :
class Solution
{
    public:
    bool isAnagram(string a, string b){
        if(a.length()!=b.length())
            return false;
        int charCount[26]={0};
        for(int i=0;i<a.length();i++)
        {
            charCount[a[i]-'a']++;
        }
        for(int i=0;i<b.length();i++)
        {
            if(charCount[b[i]-'a']== 0)
            {
                return false;
            }
            charCount[b[i]-'a']--;
        }
        return true;
    }

};
