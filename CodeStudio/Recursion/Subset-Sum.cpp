Ques : https://www.codingninjas.com/studio/problems/subset-sum_3843086

Solution : 
// TC : O(2^n + 2^nlog(2^n)) and SC : O(2^n)
void helper(int ind,vector<int> num, vector<int> &ans,int sum)
{
	if(ind==num.size())
	{
		ans.push_back(sum);
		return;
	}
	sum+=num[ind];
	helper(ind+1,num,ans,sum);
	sum-=num[ind];
	helper(ind+1,num,ans,sum);
}

vector<int> subsetSum(vector<int> &num){
		int sum=0;
		vector<int> ans;
		helper(0,num,ans,sum);
		sort(ans.begin(),ans.end());
		return ans;
}
