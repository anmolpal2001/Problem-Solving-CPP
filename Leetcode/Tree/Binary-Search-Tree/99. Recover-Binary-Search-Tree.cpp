Ques : https://leetcode.com/problems/recover-binary-search-tree/

Solution : 
// TC : O(n) and SC : O(n) for recursive stack
class Solution {
    private:
        TreeNode* first,*last,*prev,*middle;
public:
    void inorder(TreeNode*root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val))
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=prev=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) 
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};
