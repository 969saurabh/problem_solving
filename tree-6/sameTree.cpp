//https://leetcode.com/problems/same-tree/description/
lass Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
        return true;
        if((p==NULL||q==NULL)||(p->val!=q->val))
        return false;
        return  isSameTree(p->left,  q->left) && isSameTree(p->right,  q->right); //return true if both subtree equal;
    }
};