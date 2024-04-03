
#include<bits/stdc++.h>
using namespace std;
bool checkOneChild(vector<int> &preorder)
{
    int l_bound=INT_MIN,u_bound=INT_MAX;
    int n=preorder.size();
    for(int i=1;i<n;i++)
    {
         if(preorder[i]<=l_bound||preorder[i]>=u_bound)
         {
             return false;
         }
         if(preorder[i]>preorder[i-1])
         {
             l_bound=preorder[i-1];
         }
         else
         {
             u_bound=preorder[i-1];
         }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> preorder(n);
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    bool ans=checkOneChild(preorder);
    cout<<ans;

    return 0;
}