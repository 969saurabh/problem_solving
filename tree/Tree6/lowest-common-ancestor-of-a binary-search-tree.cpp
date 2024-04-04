//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1223292788/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||(p->val<root->val&&q->val>root->val)||(q->val<root->val&&p->val>root->val))
        return root;
        if(p->val<root->val)
        return lowestCommonAncestor(root->left,p,q);
        else
       return lowestCommonAncestor(root->right,p,q);
    }
};