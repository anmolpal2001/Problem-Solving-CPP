Ques : https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957

Solution : 
int isSorted(int n, vector<int> a) {
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            return 0;
        }
    }
    return 1;
}
