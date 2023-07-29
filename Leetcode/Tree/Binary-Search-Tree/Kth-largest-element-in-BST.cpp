Ques : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Solution : 
// solution-1
class Solution
{
    public:
    int solve(Node* root,int &K)
    {
        if(root==NULL) return -1;
        int right = solve(root->right,K);
        if(right!=-1)
            return right;
        K--;
        if(K==0)
        {
            return root->data;
        }
        return solve(root->left,K);
    }
    int kthLargest(Node *root, int K)
    {
        return solve(root,K);
    }
};

// solution-2
int countNodes(Node*root)
    {
        if(root==NULL)  return 0;
         return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int solve(Node* root,int &i,int &k)
    {
        if(root==NULL) return -1;
        int left = solve(root->left,i,k);
        if(left!=-1)
            return left;
        i++;
        if(i==k)
            return root->data;
        return solve(root->right,i,k);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int i=0;
        int n = countNodes(root);
        int j = n-K+1;
        return solve(root,i,j);
    }
