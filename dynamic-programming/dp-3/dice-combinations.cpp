//https://cses.fi/problemset/result/9319762/
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
int main()
{
    int n;
    cin>>n;
    vector<long long> ways(n+1,0);
    for(int i=1;i<7&&i<=n;i++)
    {  
       int j=i;
       while(j>0){
       ways[i]+=ways[i-j];
       j--;
       }
       ways[i]++;
    }
    for(int i=7;i<=n;i++)
    {
        ways[i]=(ways[i-1]+ways[i-2]+ways[i-3]+ways[i-4]+ways[i-5]+ways[i-6])%mod;
    }
    cout<<ways[n];
    return 0;
}
