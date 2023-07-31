Ques : https://leetcode.com/problems/binary-search-tree-iterator/

Solution : 
// TC : O(1) and SC : O(h)
class BSTIterator {
    private:
    stack<TreeNode*> myStack;
    void pushAll(TreeNode* root)
    {
        for(;root!=NULL;myStack.push(root),root=root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};
