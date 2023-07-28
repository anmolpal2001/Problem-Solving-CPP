Ques : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Solution : 
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(i==count-1)
                {
                    curr->next=NULL;
                }
                else{
                    curr->next=q.front();
                }
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return root;
    }
};
