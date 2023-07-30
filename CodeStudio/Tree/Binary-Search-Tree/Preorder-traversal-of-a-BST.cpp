Ques : https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111

Solution : 
// TC : O(n) and SC : O(h)
BinaryTreeNode<int>* solve(vector<int>&preorder,int mini,int maxi,int &i)
{
    if(i>=preorder.size())
        return NULL;
    if(preorder[i]<mini || preorder[i] > maxi)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i=0;
    int maxi = INT_MAX;
    int mini = INT_MIN;
    return solve(preorder,mini,maxi,i);
}
