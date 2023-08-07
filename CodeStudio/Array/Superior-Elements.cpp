Ques : https://www.codingninjas.com/studio/problems/superior-elements_6783446

Solution : 
// TC : O(N logN) and SC : O(N)
vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n=a.size();
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>maxi)
        {
            ans.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }
    sort(a.begin(),a.end());
    return ans;
}
