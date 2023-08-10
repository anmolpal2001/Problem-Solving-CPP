Ques : https://leetcode.com/problems/transpose-matrix/

Solution : 
// TC : O(N^2) and SC : O(N^2)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> transpose(m,vector<int>(n));
        for(int i=0;i<n;i++)
	    {
            for(int j=0;j<m;j++)
            {
                transpose[j][i]=matrix[i][j];
            }
	    }
        return transpose;
    }
};
