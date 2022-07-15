// Question : https://www.codingninjas.com/codestudio/problems/find-unique_625159

#include<bits/stdc++.h>
using namespace std;

// Solution 2 : using map
int findUnique(vector<int> &v)
{
    map<int,int> m;
    for(auto i:v)
    {
        m[i]++;
    }
    int ans;
    for(auto pr:m)
    {
        if(pr.second==1)
        {
            ans=pr.first;
        }
    }
    return ans;
}

// Solution 1 : using xor 
int findUnique(vector<int> &v)
{
  int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans=ans^v[i];
    }
    return ans;
}


int main()
{
    vector<int> v;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans=findUnique(v);
    cout<<ans;
}
