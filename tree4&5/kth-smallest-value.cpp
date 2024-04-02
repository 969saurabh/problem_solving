//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1221477533/
class Solution {
public:
    void kthSmall(TreeNode* root,int k,int &count,int &ans)
    {
        if(root==NULL)
        return ;
        kthSmall(root->left,k,count,ans);
        count+=1;
         if(count==k) //for kth node store node value
        ans=root->val;
        //it optimise code little bit 
        if(count<k) //if kth node is not in the left subtree then only traverse left
        {
            kthSmall(root->right,k,count,ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans=0;
        kthSmall(root,k,count,ans);
        return ans;
    }
};