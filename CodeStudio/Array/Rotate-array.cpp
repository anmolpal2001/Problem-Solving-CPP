Ques : https://www.codingninjas.com/studio/problems/rotate-array_1230543

Solution : 
// TC : O(n) and SC : O(1)
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
void leftRotate(int arr[],int n,int d)
{
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int d;
    cin>>d;
    leftRotate(arr,n,d);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}