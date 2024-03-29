//https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
 vector<vector<int>> result;
    void allPath(TreeNode *root,int targetSum,vector<int> path)
    {
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL)
        {
            targetSum-=root->val;
            if(targetSum==0)
            {
               path.push_back(root->val);
               result.push_back(path);
            }
        }
        path.push_back(root->val);
        allPath(root->left,targetSum-root->val,path);
        allPath(root->right,targetSum-root->val,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        allPath(root,targetSum,path);
        return result;
    }
};