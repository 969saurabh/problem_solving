//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1223171021/
class Solution {
public:
    void inorderTraversal(TreeNode *root,vector<int> &inorder)
    {
       if(root==NULL)
       return ;
       inorderTraversal(root->left,inorder);
       inorder.push_back(root->val);
       inorderTraversal(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
      //  TreeNode* rot=new TreeNode(5);
        vector<int> inorder;
        inorderTraversal(root,inorder);
        int i=0,j=inorder.size()-1;
        while(i<j)
        {
            if(inorder[i]+inorder[j]==k)
            return true;
            else if(inorder[i]+inorder[j]>k)
            j--;
            else
            i++;
        }
        return false;
    }
};