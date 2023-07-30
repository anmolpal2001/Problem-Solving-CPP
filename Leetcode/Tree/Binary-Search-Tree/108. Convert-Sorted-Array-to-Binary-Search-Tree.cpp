Ques : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Solution :
class Solution {
public:
    TreeNode* arrayToBST(int s,int e, vector<int>&nums)
    {
        if(s>e)
            return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=arrayToBST(s,mid-1,nums);
        root->right=arrayToBST(mid+1,e,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(0,nums.size()-1,nums);
    }
};
