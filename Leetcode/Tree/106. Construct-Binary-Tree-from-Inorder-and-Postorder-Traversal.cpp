Ques : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Solution : 
class Solution {
public:
    TreeNode* cTree(vector<int>&in,vector<int>&post,int &index,int is,int ie,map<int,int>&nodeToIndex)
    {
        // best case
        if(index < 0 || is>ie)
            return NULL;
        // create a root node
        TreeNode* root = new TreeNode(post[index--]);
        // find root's index in inorder
        int inIndex = nodeToIndex[root->val];
        // recursive calls
        root->right = cTree(in,post,index,inIndex+1,ie,nodeToIndex);
        root->left = cTree(in,post,index,is,inIndex-1,nodeToIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int istart = 0;
        int iend = inorder.size()-1;
        int n = postorder.size();
        int postIndex = n-1;
        map<int,int> nodeToIndex;
        // node to index mapping
        for(int i=0;i<=iend;i++)
        {
            nodeToIndex[inorder[i]]=i;
        }
        TreeNode * ans = cTree(inorder,postorder,postIndex,istart,iend,nodeToIndex);
        return ans;
    }
};
