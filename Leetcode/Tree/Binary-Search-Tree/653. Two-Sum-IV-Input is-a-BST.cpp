Ques : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Solution :
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL) 
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
    inorder(root,ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j)
    {
        int sum = ans[i] + ans[j];
        if(sum == k)
        {
            return true;
        }
        else if(sum>k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
    }
};
