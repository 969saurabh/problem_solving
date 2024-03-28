//https://www.geeksforgeeks.org/problems/odd-even-level-difference/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
  public:
    /*You are required to complete this function*/
    void levelDiff(Node *root,int &oddSum,int &evenSum,int level)
    {
        if(root==NULL)
        return ;
        if(level%2==0)
        {
            evenSum+=root->data;
        }
        else
        oddSum+=root->data;
        levelDiff(root->left,oddSum,evenSum,level+1);
        levelDiff(root->right,oddSum,evenSum,level+1);
        
    }
    int getLevelDiff(Node *root)
    {
       //Your code here
       int oddSum=0,evenSum=0;
        levelDiff(root,oddSum,evenSum,1);
        return oddSum-evenSum;
    }
};
