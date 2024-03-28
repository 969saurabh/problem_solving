//https://www.naukri.com/code360/problems/tree-height_4609628
int heightOfTree(TreeNode<int> *root,int height)
{
    if(root==NULL)
    return height;  
    else //return max height from both of subtree
    return max(heightOfTree(root->left,height+1),heightOfTree(root->right,height+1));
}
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    return heightOfTree(root,0);  //call function

}