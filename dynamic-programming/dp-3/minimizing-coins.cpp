//https://cses.fi/problemset/result/9319921/
 
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
int main()
{   
    int n,amount;
    cin>>n>>amount;
    vector<int> denom(n);
    for(int i=0;i<n;i++)
    {
        cin>>denom[i];
    }
    vector<int> minimal(amount+1,-1);
    minimal[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=denom[i];j<=amount;j++)
        {
            if(minimal[j]!=-1&&minimal[j-denom[i]]!=-1){
            minimal[j]=min(minimal[j],minimal[j-denom[i]]+1);
            }
            else if(minimal[j-denom[i]]!=-1){
                
            minimal[j]=minimal[j-denom[i]]+1;
            }
        }
    }
    cout<<minimal[amount];
    return 0;
}
