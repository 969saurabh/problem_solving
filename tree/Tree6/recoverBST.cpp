//https://leetcode.com/problems/recover-binary-search-tree/
class Solution {
public:
TreeNode* first=NULL,*second=NULL,*prev=NULL,*last=NULL;
void swapm(TreeNode* r1,TreeNode* r2)
    {
        int temp=r1->val;
        r1->val=r2->val;
        r2->val=temp;

    }
 void findnode(TreeNode* root)
        {
            if(root==NULL)
            return ;
            findnode(root->left);
            if(prev!=NULL&&root->val<prev->val)
            {
                if(first==NULL)
                {
                    first=prev;
                    second=root;
                }
                else
                last=root;
            }
            prev=root;
            findnode(root->right);
        }
        void recoverTree(TreeNode* root){
            findnode(root);
            if(last==NULL)
            {
                swapm(first,second);
            }
            else
            {
                swapm(first,last);
            }
        }
}