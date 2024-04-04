//
//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int data;
        if(root==NULL)
        return res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty())
        {
         TreeNode *temp=myqueue.front();
          myqueue.pop();
          if(temp==NULL)
          {  
              res.push_back(data);
              myqueue.push(NULL);
             temp= myqueue.front();
             myqueue.pop();
             if(temp==NULL)
             return res;
          }
          if(temp->left!=NULL)
          myqueue.push(temp->left);
           if(temp->right!=NULL)
          myqueue.push(temp->right);
          data=temp->val;

        } 

      return res;

    }
};