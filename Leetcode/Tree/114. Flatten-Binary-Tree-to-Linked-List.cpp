Ques : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Solution :
// TC : O(n) and SC : O(1);
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
