Ques : https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278

Solution : 
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}
