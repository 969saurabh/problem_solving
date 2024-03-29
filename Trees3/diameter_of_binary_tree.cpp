//can be optimised
//https://leetcode.com/problems/diameter-of-binary-tree
class Solution {
public:
    int height(TreeNode *root,int h)
    {
        if(root==NULL)
        return h;
        return max(height(root->left,h+1),height(root->right,h+1));
    }
    void diameterOfbinary(TreeNode *root,int &diameter)
    {
        if(root==NULL)
        return ;
        int x=height(root->left,0)+height(root->right,0);
        diameter=max(x,diameter);
        diameterOfbinary(root->left,diameter);
        diameterOfbinary(root->right,diameter);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        diameterOfbinary(root,diameter);
        return diameter;
    }
};