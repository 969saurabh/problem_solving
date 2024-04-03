//https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
/*##############################################################################
  Time Complexity:O((2*n)+(2*n))
  Space Complexity:O((2*n)+h); 
##############################################################################*/
class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
   void inorderTraversal(Node *root,vector<int> &v)
    {
        if(root==NULL)
        return ;
        inorderTraversal(root->left,v);
        v.push_back(root->data);
        inorderTraversal(root->right,v);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int> v1,v2;
     inorderTraversal(root1,v1);
     inorderTraversal(root2,v2);
     vector<int> common;
     for(int i=0,j=0;i<v1.size()&&j<v2.size(); )
     {
        if(v1[i]==v2[j])
        {
            common.push_back(v1[i]);
            i++;
            j++;
        }
        else
        {
            if(v1[i]>v2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
     }
     return common;
    }
};

