// Question : https://leetcode.com/problems/valid-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private :
    bool isValid(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            return 1;
        }
        return 0;
    }
    char toLowerCase(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        {
            return ch;
        }
        else
        {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkPalindrome(string st)
    {
        int s=0;
        int e=st.length()-1;
        while(s<=e)
        {
            if(st[s]!=st[e])
            {
                return 0;
            }
            else
            {
                s++;
                e--;
            }
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
        for(int i=0;i<temp.length();i++)
        {
            temp[i]=toLowerCase(temp[i]);
        }
        
        return checkPalindrome(temp);
    }
};
