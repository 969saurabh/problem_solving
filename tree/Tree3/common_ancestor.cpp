//
class Solution {
public:

    void  findAncestor(TreeNode *root,TreeNode *node,vector<TreeNode *> ancestor,vector<TreeNode *> &ancestors)
    {
       if(root==NULL)
       return ;
       if(root==node)
       {
         ancestors.push_back(node);
         ancestors=ancestor;
         return ;
       }
       else{
       ancestors.push_back(root);
       findAncestor(root->left,node,ancestor,ancestors);
       findAncestor(root->right,node,ancestor,ancestors);
       }
     
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> ancestor;
         vector<TreeNode *> ancestorP,ancestorQ;
        findAncestor(root,p,ancestor,ancestorP);
        findAncestor(root,q,ancestor,ancestorQ);
        int i=0;
        while(i<ancestorP.size()&&i<ancestorQ.size())
        {
            if(ancestorP[i]!=ancestorQ[i])
            {
                break;
            }
            i++;
        }

        return ancestorP[i-1];
    }
};