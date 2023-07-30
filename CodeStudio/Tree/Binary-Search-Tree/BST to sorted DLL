Ques : https://www.codingninjas.com/studio/problems/bst-to-sorted-dll_1263694

Solution : 
TreeNode<int>* doublyLL(TreeNode<int>*root,TreeNode<int>*&prev)
{
    if (root == nullptr)
        return root;
    TreeNode<int>* head = doublyLL(root->left, prev);
    if (prev == nullptr)
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    doublyLL(root->right, prev);
    return head;
}
TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
	TreeNode<int>*prev=NULL;
    return doublyLL(root,prev);
}
