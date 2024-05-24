//https://cses.fi/problemset/result/9320658/
 
#include <bits/stdc++.h>
#define d 1000000007
using namespace std;
int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int> denom(n);
    for(int i=0;i<n;i++)
    {
        cin>>denom[i];
    }
    vector<long long> ways(amount+1,0);
    ways[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=denom[i];j<=amount;j++)
        {
            ways[j]=(ways[j]+ways[j-denom[i]])%d;
        }
    }
    cout<<ways[amount];
    return 0;
}
