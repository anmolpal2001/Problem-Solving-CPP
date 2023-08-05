Ques : https://www.codingninjas.com/studio/problems/frequency-in-a-sorted-array_893286

Solution : 
// TC : O(logn) and SC : O(1)
int first(vector<int>&arr,int x)
{
    int s=0,e=arr.size()-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int last(vector<int>&arr,int x)
{
    int s=0,e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans=0;
    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int countOccurrences(vector < int > arr, int x) {
    int i = first(arr,x);
    if(i==-1)
    {
        return 0;
    }
    int j=last(arr,x);

    return j-i+1;
}
