//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
class Solution {
public:
 map<int,vector<pair<int,int>>> result;  //keep record of (x,y) position of node 
 /*bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}*/
    void traverse(TreeNode *root,int pos,int h)
    {
       if(root==NULL)
       return ;
       //pos(x) use as key and pos(y) is store as pair
       result[pos].push_back(pair<int,int>(h,root->val)); 
       traverse(root->left,pos-1,h+1);
       traverse(root->right,pos+1,h+1); 

    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        traverse(root,0,0); //call function
        vector<vector<int>> verticalTraverse; //storing result
        //declare iterator for traversing map
         map<int, vector<pair<int,int>>>::iterator itr=result.begin(); 
         while(itr!=result.end())
         {
            vector<int> temp;
            sort(itr->second.begin(),itr->second.end()); //sort based on pos(y)
            //traversing and storing node value according to its level
            for(int i=0;i<itr->second.size();i++)
            temp.push_back(itr->second[i].second); 
            verticalTraverse.push_back(temp);
            itr++;
         }
        return verticalTraverse;
    }
};