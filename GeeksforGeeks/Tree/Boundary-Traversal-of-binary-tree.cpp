Ques : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Solution : 
class Solution {
public:
    void traverseLeft(Node *root, vector<int>&ans)
    {
        if((root==NULL) || (root->left==NULL && root->right==NULL))
            return;
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left,ans);
        else
            traverseLeft(root->right,ans);
            
    }
    void traverseLeaf(Node *root, vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
            
    }
    void traverseRight(Node *root, vector<int>&ans)
    {
        if((root==NULL) || (root->left==NULL && root->right==NULL))
            return;
        if(root->right)
            traverseRight(root->right,ans);
        else
            traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)
            return ans;
        ans.push_back(root->data);
        
        // print left part
        traverseLeft(root->left,ans);
        
        // print leaf node
        // left sub-tree
        traverseLeaf(root->left,ans);
        //right sub-tree
        traverseLeaf(root->right,ans);
        
        // print right part
        traverseRight(root->right,ans);
        
        return ans;
    }
};
