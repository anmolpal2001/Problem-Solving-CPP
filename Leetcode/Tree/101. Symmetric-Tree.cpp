Ques : https://leetcode.com/problems/symmetric-tree/

Solution :
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r)
    {
        if(l==NULL && r==NULL)
            return true;
        else if(l && r)
        {
            if(l->val!=r->val)
                return false;
            return check(l->left,r->right) && check(l->right,r->left);
        }           
        else 
            return false;
    }
    bool isSymmetric(TreeNode* root) {
            
        return check(root->left,root->right);
    }
};
