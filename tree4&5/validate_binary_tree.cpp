//https://leetcode.com/problems/validate-binary-search-tree/submissions/1221329675/
class Solution {
public:
    bool checkValid(TreeNode *root,long long lower_bound,long long upper_bound)
    {
        if(root==NULL)
        return true;
        //check if node id valid for bst
        if(root->val<=lower_bound||root->val>=upper_bound)
        return false;
        //check if left and right subtree is valid bst
        return checkValid(root->left,lower_bound,root->val)&&checkValid(root->right,root->val,upper_bound);

    }
    bool isValidBST(TreeNode* root) {
        //handle edge case where node val is int max;
        long long l=INT_MIN,u=INT_MAX;
        return checkValid(root,l-1,u+1);
    }
};