Ques : https://leetcode.com/problems/find-largest-value-in-each-tree-row/

Solution : 
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue <TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int count = q.size();
            int mx=INT_MIN;
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                mx = max(mx,curr->val);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
