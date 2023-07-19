Ques : https://leetcode.com/problems/binary-tree-level-order-traversal

Solution : 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue <TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);

        }
        return ans;
    }
};
