Ques : https://leetcode.com/problems/binary-tree-paths/

Solution : 
// TC : O(n) and SC : O(n)
class Solution {
public:
    void traversePath(TreeNode* root, vector<string> &ans,string temp)
    {
        if(root->left==NULL && root->right==NULL)
            ans.push_back(temp);
        if(root->left!=NULL)
            traversePath(root->left,ans,temp + "->"+to_string(root->left->val));
        if(root->right!=NULL)
            traversePath(root->right,ans,temp + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)  return ans;
        traversePath(root,ans,to_string(root->val));
        return ans;
    }
};
