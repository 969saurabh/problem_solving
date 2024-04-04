//https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
     vector<int> res;
        int data;
        if(root==NULL)
        return res;
        queue<BinaryTreeNode<int>*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);
            res.push_back(root->data);
        while(!myqueue.empty())
        {
        BinaryTreeNode<int> *temp=myqueue.front();
          myqueue.pop();
          if(temp==NULL)
          {  
              myqueue.push(NULL);
             temp= myqueue.front();
             myqueue.pop();
             if(temp==NULL)
             return res;
               res.push_back(temp->data);
          }
          if(temp->left!=NULL)
          myqueue.push(temp->left);
           if(temp->right!=NULL)
          myqueue.push(temp->right);

        } 

      return res;
}