Ques : https://leetcode.com/problems/diameter-of-binary-tree/

Solution : 

// Naive Solution - O(n^2)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) 
            return 0;
        else
            return 1 + max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) 
            return 0;
        int d1 = height(root->left) + height(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        return max(d1, max(d2,d3));
    }
};

// Efficient Solution - O(n)
class Solution {
public:
    int res=0;
    int solve(TreeNode *  root){
        if(!root)  return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        res = max(res,l+r+1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res-1;
    }
