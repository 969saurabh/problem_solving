//
//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void topViewOfTree(Node *root,int x,int y,map<int,int> &topview,map<int,int> &level )
    {
        if(root==NULL)
        return ;
        if(topview.find(x)==topview.end())
        {
            topview[x]=root->data;
            level[x]=y;
        }
        else
        {
            if(level[x]>=y)
            {
                topview[x]=root->data;
                level[x]=y;
            }
        }
         topViewOfTree(root->right,x+1,y+1,topview,level);
        topViewOfTree(root->left,x-1,y+1,topview,level);
       
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> topview;
        map<int,int> level;
        vector<int> ans;
        topViewOfTree(root,0,0,topview,level);
        map<int,int>::iterator it=topview.begin();
        while(it!=topview.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }

};
