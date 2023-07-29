Ques : https://leetcode.com/problems/validate-binary-search-tree/

Solution : 
class Solution {
public:
    bool checkBST(TreeNode* root,long int min, long int max)
    {
        if(root==NULL) return true;
        if(root->val > min && root->val < max){
            return checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max);
        }
        return false;

    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
};
