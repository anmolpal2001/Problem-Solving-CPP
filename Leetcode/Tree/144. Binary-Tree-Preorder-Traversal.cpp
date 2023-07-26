Ques : https://leetcode.com/problems/binary-tree-preorder-traversal/

Solution : 
// Using Recursion
class Solution {
    private:
    void preorder(TreeNode* root,vector<int>&ans)
    {
        if(!root)return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);

        return ans;
    }
};

// Using Iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(st.empty()==false)
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right !=NULL)
                st.push(root->right);
            if(root->left != NULL)
                st.push(root->left);
        }
        return ans;
    }
};
