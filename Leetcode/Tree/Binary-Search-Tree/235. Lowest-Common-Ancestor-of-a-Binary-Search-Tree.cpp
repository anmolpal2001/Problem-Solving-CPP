Ques : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Solution : 
// TC : O(n) and SC : O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL)
        {
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }
};
