Ques  : https://leetcode.com/problems/set-matrix-zeroes/

Solution : 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int row = matrix.size();
        int col = matrix[0].size();
        // col => matrix[0][..]
        // row => matrix[..][0]
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    //mark the i-th row
                    matrix[i][0]=0;
                    // mark the j-th col
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col0=0;
                }
            }
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]!=0)
                {
                    // check for row & col
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0] == 0)
        {
            // mark the col
            for(int j=0;j<col;j++)
            {
                matrix[0][j]=0;
            }
        }
        if(col0 == 0)
        {
            // mark the row
            for(int i=0;i<row;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};
