Ques : https://www.codingninjas.com/studio/problems/print-subsequences_624391

Solution : 
// TC : O(2^n * n) and SC : O(N)
void print(char input[],int n,vector<char> &res,int ind)
{
    if(ind==n)
    {
        for(auto it:res)
        {
            cout<<it;
        }
        cout<<endl;
        return;
    }
    print(input, n, res, ind+1);
    res.push_back(input[ind]);
    print(input, n, res, ind+1);
    res.pop_back();
}
void printSubsequences(char input[]) {
    int n=strlen(input);
    vector<char> res;
    print(input, n,res,0);

}
