// Question : https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397 

#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    int ans=0;
    for(int i=0;i<5;i++)
    {
        ans=ans^arr[i];
    }
    for(int i=0;i<5;i++)
    {
        ans=ans^i;
    }
    return ans;
}
    
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> arr;
        int size,a; 
        cin>>size;
        for(int i=0;i<size;i++)
        {
            cin>>a;
            arr.push_back(a);
        }
        int ans = findDuplicate(arr);
        cout<<ans<<endl;
    }
}

    
