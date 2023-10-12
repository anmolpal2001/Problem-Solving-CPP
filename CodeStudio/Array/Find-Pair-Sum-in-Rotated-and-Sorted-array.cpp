Ques : https://www.codingninjas.com/studio/problems/find-pair-sum-in-rotated-and-sorted-array_985350

Solution : 
// TC : O(N) and SC : O(1)
int findPairSum(vector<int> arr, int target)
{
    int n=arr.size();
	int start=0;
	int end=n-1;
	for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
    	    end=i;
            start=i+1;
	        break;
        }
    }		
	while(end>=0&&start<n)
    {
        int sum=arr[start]+arr[end];
		if(start==end) return false;
		if(sum<target) start++;
        else if(sum>target) end--;
		else return true;
    }
    if(end<0&&start==n)return false;
	if(end<0) end=n-1;
	else start=0;
	while(start<end){
        int sum=arr[start]+arr[end];
		if(sum<target) start++;
		else if(sum>target) end--;
		else return true;
	}
	return false;
}
