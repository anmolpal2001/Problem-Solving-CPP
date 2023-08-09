Ques : https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740

Solution : 
// TC : O(NlogN) + O(N) and SC : O(1)
int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(),a.end());
    int longest=1;
    int cnt=0;
    int lastSmaller=INT_MIN;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]-1 == lastSmaller)
        {
            cnt=cnt+1;
            lastSmaller=a[i];
        }
        else if(a[i]!=lastSmaller)
        {
            cnt=1;
            lastSmaller=a[i];
        }
        longest=max(longest,cnt);
    }
    return longest;
}
