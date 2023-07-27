Ques : https://leetcode.com/problems/validate-binary-search-tree/

Solution : 
class Solution {
public:
    bool checkBST(TreeNode* root,long int min, long int max)
    {
        if(root==NULL) return true;
        if(root->val > min && root->val < max){
            bool left = checkBST(root->left,min,root->val);
            bool right = checkBST(root->right,root->val,max);
            return left&&right;
        }
        return false;

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right ==NULL)
            return true;
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
};
