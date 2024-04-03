//https://leetcode.com/problems/path-sum-iii/
class Solution {
public:
int count=0;
    void allPath(TreeNode *root,long long target)
    {
        if(root==NULL)
        return ;
            target-=root->val;
            if(target==0)
            {
               count++;
            }
        allPath(root->left,target);
        allPath(root->right,target);
    }
    void traverse(TreeNode *root,long long target)
    {
        if(root==NULL)
        return ;
        allPath(root,target);
        traverse(root->right,target);
        traverse(root->left,target);
   
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long t=targetSum;
        traverse(root,t);
        return count;
    }
};