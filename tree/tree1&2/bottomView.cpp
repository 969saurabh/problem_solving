//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
class Solution {
  public:
  void bottomViewOfTree(Node *root,int x,int y,map<int,int> &bottomview,map<int,int> &level )
    {
        if(root==NULL)
        return ;
        if(bottomview.find(x)==bottomview.end())
        {
            bottomview[x]=root->data;
            level[x]=y;
        }
        else
        {
            if(level[x]<y)
            {
                bottomview[x]=root->data;
                level[x]=y;
            }
        }
         bottomViewOfTree(root->right,x+1,y+1,bottomview,level);
        bottomViewOfTree(root->left,x-1,y+1,bottomview,level);
       
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
          map<int,int> bottomview;
        map<int,int> level;
        vector<int> ans;
        bottomViewOfTree(root,0,0,bottomview,level);
        map<int,int>::iterator it=bottomview.begin();
        while(it!=bottomview.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};