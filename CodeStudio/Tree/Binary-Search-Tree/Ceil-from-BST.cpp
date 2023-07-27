Ques : https://www.codingninjas.com/studio/problems/ceil-from-bst_920464

Solution :

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    while(node!=NULL)
    {
        // if(node->data == x)
        //     ans = x;
         if(node->data < x)
        {
            node=node->right;
        }
        else
        {
            ans = node->data;
            node=node->left;
        }
    }
    return ans;
}
