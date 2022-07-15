// Question : https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633

#include<bits/stdc++.h>
using namespace std;

// Solution 1 : using iterator
bool isPalindrome(string s)
{
    string::iterator it;
    string::reverse_iterator rit;
    it=s.begin();
    rit=s.rbegin();
    while(it!=s.end() && rit!=s.rend())
    {
        while(!isalnum(*rit) && rit!=s.rend())
        {
            rit++;
        }
        while(!isalnum(*it) && it!=s.end())
        {
            it++;
        }
        if(it==s.end() || rit==s.rend())
        {
            break;
        }
        if(tolower(*it)!=tolower(*rit))
        {
            return 0;
        }
        rit++;
        it++;
    }
    return 1;
}

// Solution 2 : using 2 pointer 
bool checkPalindrome(string s)
{
    string temp;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        {
            temp.push_back(s[i]);
        }
    }
    for(int i=0;i<temp.length();i++)
    {
        temp[i]=tolower(temp[i]);
    }
    int st=0;
    int e=temp.length()-1;
    while(st<=e)
    {
        if(temp[st]!=temp[e])
        {
            return 0;
        }
        else
        {
            st++;
            e--;
        }
    }
    return 1;
}

int main()
{
    string s;
    getline(cin,s);
    isPalindrome(s)?cout<<"YES":cout<<"NO";
    
}
