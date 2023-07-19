Ques : https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

Solution : 
// function should print the nodes at k distance from root
void printKdistance(struct Node * root,int k, vector<int> &ans)
{
    if(root==NULL) return;
    if(k==0) ans.push_back(root->data);
    else
    {
        printKdistance(root->left,k-1,ans);
        printKdistance(root->right,k-1,ans);
    }
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int> ans;
  printKdistance(root,k,ans);
  return ans;
 
}
