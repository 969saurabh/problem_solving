//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/1223392947/
TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> mystack;
        stack<int> upper;
        TreeNode *node=new TreeNode(preorder[0]);
        mystack.push(node);
        upper.push(INT_MAX);
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode* temp=mystack.top();
            if(temp->val>preorder[i])
            {
              temp->left=new TreeNode(preorder[i]);
              upper.push(temp->val);
              mystack.push(temp->left);
            }
            else
            {
                int t=upper.top();
               while(t<preorder[i])
               {
                 upper.pop();
                 mystack.pop();
                 t=upper.top();
               }
               temp=mystack.top();
               temp->right=new TreeNode(preorder[i]);
               mystack.push(temp->right);
               upper.push(upper.top());
            }
        }
        return node;
    }