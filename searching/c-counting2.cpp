//https://atcoder.jp/contests/abc231/tasks/abc231_c
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find_stud(vector<int> &a,int n,int t)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(a[mid]>=t)
        {
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
    }
    return n-j-1;
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> b(q);
    for(int i=0;i<q;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<q;i++)
    {
        cout<<find_stud(a,n,b[i])<<endl;
        
    }

    return 0;
}
