//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1221345098/
class Solution {
public:
    TreeNode* buildBst(vector<int> &nums,int lower,int upper)
    {
        if(lower>upper)
        return NULL;
       TreeNode *root=new TreeNode(nums[(lower+upper)/2]);
       //built left  bs subtree
        root->left=buildBst(nums,lower,(lower+upper)/2-1);
         //built right  bs subtree
        root->right=buildBst(nums,(lower+upper)/2+1,upper);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBst(nums,0,nums.size()-1);
    }
};