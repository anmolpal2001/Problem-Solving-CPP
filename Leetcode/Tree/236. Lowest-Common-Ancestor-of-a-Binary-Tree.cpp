Ques : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Solution : 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL && right==NULL)
            return NULL;
        if(left!=NULL && right==NULL)  
            return left;
        if(left==NULL && right!=NULL) 
            return right;
        else
            return root;
    }
};
