//https://leetcode.com/problems/range-sum-of-bst/submissions/1222377807/
class Solution {
public:
    void sumBST(TreeNode* root,int low,int high,int &sum)
    {
        if(root==NULL)
        return ;
        if(root->val>=low&&root->val<=high)
        {
            sum+=root->val;
        }
        sumBST(root->left,low,high,sum);
        sumBST(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
       sumBST(root,low,high,sum);
        return sum;
    }
};