Ques : https://leetcode.com/problems/insert-into-a-binary-search-tree/

Solution : 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * temp = new TreeNode(val);
        TreeNode * parent = NULL, * curr = root;
        while(curr!=NULL)
        {
            parent = curr;
            if(curr->val > val)
                curr = curr->left;
            else if (curr->val < val)
                curr = curr->right;
            else
                return root;
        }
        if(parent==NULL)
            return temp;
        if(parent->val > val)
            parent->left = temp;
        else 
            parent->right = temp;
        return root;
    }
};
