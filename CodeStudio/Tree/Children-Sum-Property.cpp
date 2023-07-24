Ques : https://www.codingninjas.com/studio/problems/children-sum-property_8357239

Solution : 
bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL) 
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    int sum=0;
    if(root->left!=NULL)
        sum+=root->left->data;
    if(root->right!=NULL)
        sum+=root->right->data;
    return (root->data == sum && isParentSum(root->left) && isParentSum(root->right));
}
