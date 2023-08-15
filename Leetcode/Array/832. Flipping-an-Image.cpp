Ques : https://leetcode.com/problems/flipping-an-image/

Solution : 
// TC : O(m*n) and SC : O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        int n = image.size();
        for (int i = 0; i < n; ++i) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int temp = image[i][left];
                image[i][left] = 1 - image[i][right];
                image[i][right] = 1 - temp;
                left++;
                right--;
            }
        }
        return image;
    }
};
