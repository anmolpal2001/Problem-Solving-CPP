Ques : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Solution : 
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root==NULL)
   {
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   while(q.empty()==false)
   {
       int count = q.size();
       for(int i=0;i<count;i++)
       {
           Node* curr = q.front();
           q.pop();
           if(i==0)
           {
               ans.push_back(curr->data);
           }
           if(curr->left!=NULL)
           {
               q.push(curr->left);
           }
           if(curr->right!=NULL)
           {
               q.push(curr->right);
           }
       }
   }
   return ans;
}
