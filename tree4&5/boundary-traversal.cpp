//https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725?leftPanelTabValue=SUBMISSION
void leftboundary(TreeNode<int>* root,vector<int> &boundary)
{ 
    if(root==NULL)
    return ;
    while(root->left!=NULL||root->right!=NULL)
    {
        boundary.push_back(root->data);
        if(root->left!=NULL)
        {
            root=root->left;
        }
        else
        root=root->right;
    }
}
void bottomboundary(TreeNode<int> *root,vector<int> &boundary)
{
    if(root==NULL)
    return;
    if(root->left==NULL&&root->right==NULL)
    {
        boundary.push_back(root->data);
    }
    bottomboundary(root->left,boundary);
    bottomboundary(root->right,boundary);
}
void rightboundary(TreeNode<int> *root,vector<int> &boundary)
{
    int count=0;
    if(root==NULL)
    return ;
     while(root->left!=NULL||root->right!=NULL)
    {
        boundary.push_back(root->data);
        count++;
        if(root->right!=NULL)
        {
            root=root->right;
        }
        else
        root=root->left;
    }
    reverse(boundary.begin()+boundary.size()-count,boundary.end());
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> boundary;
    boundary.push_back(root->data);
    leftboundary(root->left,boundary);
    bottomboundary(root,boundary);
    rightboundary(root->right,boundary);
    return boundary;
}
