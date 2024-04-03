//https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
/*
time complexity:O(n);
n=no. of node;
space complexity:O(h);
h=height of tree;
*/
void ceil(Node* root,int input,int &c)
{
    if(root==NULL)
    return ;
    if(root->data>=input)
    {
        c=min(c,root->data);
    }
    ceil(root->left,input,c);
    ceil(root->right,input,c);
}

int findCeil(Node* root, int input) {
    // Your code here
    int c=INT_MAX;
    ceil(root,input,c);
    if(c==INT_MAX)
    return -1;
    return c;
}