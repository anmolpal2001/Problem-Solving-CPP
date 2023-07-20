Ques : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Solution : 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int count = q.size();
            vector<int> temp;
            for(int i=0;i<count;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL) 
                    q.push(curr->left);
                if(curr->right!=NULL) 
                    q.push(curr->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
