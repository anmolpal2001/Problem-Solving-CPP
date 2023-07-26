Ques : https://leetcode.com/problems/search-in-a-binary-search-tree/

Solution : 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!= NULL && root->val != val){
            root = (root->val > val) ? root->left : root->right ; 
        }
        return root;
    }
};
