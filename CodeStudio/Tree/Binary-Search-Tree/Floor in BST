Ques : https://www.codingninjas.com/studio/problems/floor-from-bst_920457

Solution : 

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    while(root!=NULL){
        if(root->val == X) 
            return X;
        else if(root->val > X)
        {
            root = root->left;
        }
        else 
        {
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}

