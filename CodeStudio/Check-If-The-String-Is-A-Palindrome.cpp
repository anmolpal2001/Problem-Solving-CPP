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


int main()
{
    string s;
    getline(cin,s);
    isPalindrome(s)?cout<<"YES":cout<<"NO";
    
}
