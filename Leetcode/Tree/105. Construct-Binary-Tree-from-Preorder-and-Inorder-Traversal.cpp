Ques : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Solution :
// TC : O(n) and SC : O(n);

class Solution {
public:
    
    TreeNode* cTree(vector<int>&pre,vector<int>&in,int &index,int n,int is,int ie,map<int,int>&nodeToIndex)
    {
        if(index>=n || is>ie)
            return NULL;
        TreeNode * root = new TreeNode(pre[index++]);
        int inIndex = nodeToIndex[root->val];
        root->left = cTree(pre,in,index,n,is,inIndex-1,nodeToIndex);
        root->right = cTree(pre,in,index,n,inIndex+1,ie,nodeToIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)   {
        int istart=0;
        int iend=inorder.size()-1;
        int preIndex = 0;
        int n = preorder.size();
        map<int,int> nodeToIndex;
        for(int i=0;i<=iend;i++)
        {
            nodeToIndex[inorder[i]]=i;
        }
        TreeNode* ans = cTree(preorder,inorder,preIndex,n,istart,iend,nodeToIndex);
        return ans;
    }
};
