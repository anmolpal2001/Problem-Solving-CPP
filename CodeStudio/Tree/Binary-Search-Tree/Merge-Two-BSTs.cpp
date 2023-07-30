Ques : https://www.codingninjas.com/studio/problems/h_920474

Solution : 
// TC : O(m+n) and SC : O(m+n)
vector<int> mergeArray(vector<int>&a,vector<int>&b)
{
    vector<int> ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size()&&b.size())
    {
        if(a[i]<b[j])
        {
            ans[k++]=a[i++];
        }
        else
        {
            ans[k++]=b[j++];
        }
    }
    while(i<a.size())
    {
        ans[k++]=a[i++];
    }
    while(j<b.size())
    {
        ans[k++]=b[j++];
    }
    return ans;
}

void inorder(TreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

TreeNode<int>* mergedBST(int s,int e,vector<int>&inorder)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->left=mergedBST(s,mid-1,inorder);
    root->right=mergedBST(mid+1,e,inorder);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> ans1,ans2;
    inorder(root1,ans1);
    inorder(root2,ans2);
    vector<int> mergeInorder = mergeArray(ans1,ans2);
    int size = mergeInorder.size()-1;
    return mergedBST(0,size,mergeInorder);

}

// TC : O(m+n) and SC : O(h1+h2)
void convertedToDLL(TreeNode<int>*root,TreeNode<int>*&head)
{
    if(root==NULL)
        return;
    convertedToDLL(root->right, head);
    root->right=head;
    if(head!=NULL)
        head->left=root;
    head=root;
    convertedToDLL(root->left, head);
}

TreeNode<int>* mergeDLL(TreeNode<int> *&head1,TreeNode<int>*&head2)
{
    TreeNode<int>*head=NULL;
    TreeNode<int>*tail=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else
            {
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else
            {
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL)
    {
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}

int countNodes(TreeNode<int>*&head)
{
    int cnt=0;
    TreeNode<int>* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedDLLToBST(TreeNode<int>*&head,int n)
{
    if(n<=0 || head==NULL)
        return NULL;
    TreeNode<int>* left = sortedDLLToBST(head,n/2);
    TreeNode<int>*root=head;
    root->left=left;
    head=head->right;
    root->right = sortedDLLToBST(head, n-n/2-1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // step1: make dobly linked list:
    TreeNode<int> *head1=NULL;
    convertedToDLL(root1, head1);
    head1->left=NULL;
    TreeNode<int> *head2=NULL;
    convertedToDLL(root2, head2);
    head2->left=NULL;
    // step2: merge sorted DLL.
    TreeNode<int>*head = mergeDLL(head1,head2);
       // step3:
    return sortedDLLToBST(head, countNodes(head));
}

