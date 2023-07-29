Ques : https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049

Solution : 
// TC : O(n) and SC : O(1)
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1;
    int succ = -1;
    BinaryTreeNode<int>* temp = root;
    while(temp->data!=key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp=temp->left;
        }
        else
        {
            pre = temp->data;
            temp=temp->right;
        }
    }   
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree!=NULL)
    {
        pre=leftTree->data;
        leftTree = leftTree->right;
    }
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree!=NULL)
    {
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

    // pair<int,int> ans = make_pair(pre,succ);
    return {pre,succ};
}
