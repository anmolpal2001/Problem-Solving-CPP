Ques : https://practice.geeksforgeeks.org/problems/transform-string5648/1

Solution :
// TC : O(N) and SC : O(1)
class Solution
{
    public:
    int transform (string A, string B)
    {
        int s1=0,s2=0;
        int lenA=A.length();
        int lenB=B.length();
        
        if(lenA!=lenB)
            return -1;
        unordered_map<char,int> mpp;
        for(int i=0; i<lenA; i++) 
        {
            mpp[A[i]]++;
            mpp[B[i]]--;
        }
        int ans=0;
        for(auto it:mpp) 
        {
            if(it.second!=0)
            {
                return -1;
            }
        }
        int i=lenA-1,j=lenB-1,cnt=0;
        while(i>=0 && j>=0)
        {
            if(A.at(i)==B.at(j))
            {
                i--;
                j--;
            }
            else
            {
                cnt++;
                i--;
            }
        }
        return cnt;
    }
};
