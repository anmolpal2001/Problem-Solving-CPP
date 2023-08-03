// Union of two sorted array 
Ques : https://www.codingninjas.com/studio/problems/sorted-array_6613259

Solution 1 : 
#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n=a.size();
    int m=b.size();
    vector<int> unionArray;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            if(unionArray.size()==0 || unionArray.back()!=a[i])
            {
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArray.size()==0 || unionArray.back()!=b[j])
            {
                unionArray.push_back(b[j]);
            }
            j++;   
        }
    }
    while(i<n)
    {
        if(unionArray.size()==0 || unionArray.back()!=a[i])
        {
            unionArray.push_back(a[i]);
        }
        i++;
    }
    while(j<m)
    {
        if(unionArray.size()==0 || unionArray.back()!=b[j])
        {
            unionArray.push_back(b[j]);
        }
        j++; 
    }
    return unionArray;
}


Solution 2 :
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n=a.size();
    int m=b.size();
    set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        st.insert(b[i]);
    }
    vector<int> ans(st.size());
    copy(st.begin(), st.end(), ans.begin());
 return ans;
}
