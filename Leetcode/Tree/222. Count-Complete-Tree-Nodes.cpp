Ques : https://leetcode.com/problems/count-complete-tree-nodes/

Solution : 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) 
            return 0;
        int lh=0,rh=0;
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            lh++;
            curr=curr->left;
        }
        curr = root;
        while(curr!=NULL)
        {
            rh++;
            curr=curr->right;
        }
        if(lh==rh)
            return (1<<lh)-1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
            
    }
};
