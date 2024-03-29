//https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
   vector<string> treepath(TreeNode *root,string path,vector<string> &allpath)
   {
    if(root==NULL)
    return allpath;
     if(root->left==NULL&&root->right==NULL)
    {
        string value=to_string(root->val);
        path+=value;
        allpath.push_back(path);
        return allpath;
    }
    string value=to_string(root->val);
    path+=value+"->";
   
    treepath(root->left,path,allpath);
    return treepath(root->right,path,allpath);
   }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> allpath;
       string path;
       return treepath(root,path,allpath);
    }
};