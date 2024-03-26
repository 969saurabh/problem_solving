//https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> r;
        queue<TreeNode*> q;
        if(root==NULL)
        return res;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
         struct TreeNode *temp=q.front();
           q.pop();
          if(temp==NULL)
          {  
              q.push(NULL);
              res.push_back(r);
              r.clear();
             // q.pop();
              temp=q.front();
              q.pop();
              if(temp==NULL)
              {
                  q.pop();
                  break;
              }

          }
          
          if(temp->left!=NULL)
          q.push(temp->left);
          if(temp->right!=NULL)
          q.push(temp->right);
          r.push_back(temp->val);
        // q.pop();
          
        }
        return res;
    }
};