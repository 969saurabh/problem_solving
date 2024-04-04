//https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1
class Solution
{
  public:
    Node *head=NULL;
    Node *tail=NULL;
    void bTreeToList(Node* root)
    {
        if(root==NULL)
        return ;
        bTreeToList(root->left);
        if(head==NULL)
        {
            head=root;
            tail=root;
        }
        else{
        tail->right=root;
        root->left=tail;
        tail=root;
        }
        bTreeToList(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
       bTreeToList(root);
       head->left=tail;
       tail->right=head;
        return head ;
        
    }
};