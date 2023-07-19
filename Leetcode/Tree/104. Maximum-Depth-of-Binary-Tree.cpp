Ques : https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan-v2&envId=top-100-liked

Solution : 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
    
            return max(lDepth,rDepth)+1;
        }
    }
};
