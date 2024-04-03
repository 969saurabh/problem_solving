//https://leetcode.com/problems/find-bottom-left-tree-value/description/
class Solution {
public:
    void bottomLeftValue(TreeNode *root,int currheight,int &maxheight,int &value)
    {
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL)  //last node of subtree
        {
            if(currheight>maxheight) // compare current height of subtree and previous found max height of subtree
            {
                value=root->val;
                maxheight=currheight;
            }
        }
        
         bottomLeftValue(root->left,currheight+1,maxheight,value);
         bottomLeftValue(root->right,currheight+1,maxheight,value);
         
    }
    int findBottomLeftValue(TreeNode* root) {
        int value=root->val;
        int maxheight=0;
        //pass by reference maxheight of subtree so that previous found of maxheight of subtree can be preserve
        //pass by reference value to preserve previous value while recursive call
         bottomLeftValue(root,0,maxheight,value);
        return value;
    }
};