Ques : https://www.codingninjas.com/studio/problems/linear-search_6922070

Solution : 
int linearSearch(int n, int num, vector<int> &arr)
{   
    int ind=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            ind=i;
            break;
        }
    }
    return ind;
}
