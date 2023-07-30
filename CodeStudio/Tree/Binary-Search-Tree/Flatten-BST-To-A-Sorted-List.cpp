Ques : https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459

Solution : 
// TC : O(n) and SC : O(n)
void inorder(TreeNode<int>* root,vector<int>&ans)
{
    if(root == NULL) 
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorder(root,ans);
    int n=ans.size();
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int>* curr = newRoot;
    for(int i=1;i<n;i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(ans[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}
