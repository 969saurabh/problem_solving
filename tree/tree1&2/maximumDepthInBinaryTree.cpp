//https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int depthFind(TreeNode *root,int dep)
    {
        if(root==NULL)
        return dep;
        int x=depthFind(root->right,dep+1);
        int y=depthFind(root->left,dep+1);
        return max(x,y);
    }
    int maxDepth(TreeNode* root) {
        return depthFind(root,0);
    }
};