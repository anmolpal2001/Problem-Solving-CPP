Ques : https://www.codingninjas.com/studio/problems/more-subsequence_8842355

Solution :
// Approach - 1
#include<bits/stdc++.h>

void helper(int ind,string s,vector<string>&str,int n) {
    if(n==0) {
        return;
    }
    for(int i=0;i<n;i++) 
    {
        if(i>ind && s[i]==s[i-1]) continue;
        str.push_back(s.substr(i, n));
    }
    s.pop_back();
    helper(ind,s,str,n-1);
}


string moreSubsequence(int n, int m, string a, string b)
{
    vector<string> str;
    helper(0,a,str,n);
    int n1 = str.size();
    str.clear();
    helper(0,b,str,m);
    int n2 = str.size();
    return n1 >= n2 ? a : b;;
}

// Approach - 2
#include<bits/stdc++.h>
string moreSubsequence(int n, int m, string a, string b)
{
    set<char>s1;
    set<char>s2;
    for(int i=0; i<n; i++) s1.insert(a[i]);
    for(int i=0; i<m; i++) s2.insert(b[i]);
    if(s1.size()==s2.size()) return n < m ? b : a;
    else return s1.size() < s2.size() ? b : a;
}
