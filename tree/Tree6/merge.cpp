//
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       stack<Node*>mystack1,mystack2;
       vector<int> result;
       mystack1.push(root1);
       mystack2.push(root2);
       Node *t1,*t2;
           t1=mystack1.top();
           t2=mystack2.top();
        while(t1->left!=NULL)
           {
               mystack1.push(t1->left);
               t1=t1->left;
           }
           while(t2->left!=NULL)
           {
               mystack2.push(t2->left);
               t2=t2->left;
           }
       while((!mystack1.empty())&&(!mystack2.empty()))
       {
           t1=mystack1.top();
           t2=mystack2.top();
          
           if(t1->data<t2->data)
           {
               result.push_back(t1->data);
               mystack1.pop();
               if(t1->right!=NULL)
               {
               mystack1.push(t1->right);
               t1=t1->right;
               while(t1->left!=NULL)
               {
                   mystack1.push(t1->left);
                   t1=t1->left;
               }
               }
           }
           else
           {
               result.push_back(t2->data);
               mystack2.pop();
               if(t2->right!=NULL)
               {
                   mystack2.push(t2->right);
                   t2=t2->right;
                   while(t2->left!=NULL)
                   {
                       mystack2.push(t2->left);
                       t2=t2->left;
                   }
               }
           
           }
        
       }
       while(!mystack1.empty())
       {
           t1=mystack1.top();
           result.push_back(t1->data);
           mystack1.pop();
           if(t1->right!=NULL)
           {
               mystack1.push(t1->right);
               t1=t1->right;
               while(t1->left!=NULL)
               {
                   mystack1.push(t1->left);
                   t1=t1->left;
               }
           }
       }
        while(!mystack2.empty())
       {
           t2=mystack2.top();
           result.push_back(t2->data);
           mystack2.pop();
           if(t2->right!=NULL)
           {
               mystack2.push(t2->right);
               t2=t2->right;
               while(t2->left!=NULL)
               {
                   mystack2.push(t2->left);
                   t2=t2->left;
               }
           }
       }
       return result;
    }
};