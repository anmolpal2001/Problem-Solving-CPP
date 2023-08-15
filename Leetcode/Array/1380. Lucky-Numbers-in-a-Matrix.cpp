Ques : https://leetcode.com/problems/lucky-numbers-in-a-matrix/

Solution : 
// TC : O(m*n^2) and SC : O(1)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {   
        int n = matrix.size();
    int m = matrix[0].size();
    vector<int> result;
    
    for (int i = 0; i < n; ++i) {
        int rowMin = *min_element(matrix[i].begin(), matrix[i].end());
        
        for (int j = 0; j < m; ++j) 
        {
            int colMax = matrix[0][j];
            for (int k = 0; k < n; ++k) 
            {
                colMax = max(colMax, matrix[k][j]);
            }
            if(matrix[i][j]==rowMin&&matrix[i][j]==colMax)
            {
                    result.push_back(matrix[i][j]);
                }
            }
        }
    return result;
    }
};
