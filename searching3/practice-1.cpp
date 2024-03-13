/*You have given an array A having N elements and an integer S. You have to find a maximum number X such that the sum of all its subarrays of size X is less than or equal to S.
Example Input:  
    A = [1, 3, 4, 2]  
    S = 7  
Example Output:  
    2  
Explanation:  
    All subarrays of size 2 have the sum less than 7.  
    Subarays are :  
    1. [1, 3]  
    2. [3, 4]  
    3. [4, 2]  
*/
#include <iostream>
#include<vector>
using namespace std;
bool check(vector<int> &a,int s,int n,int w)
{
    int sum=0;
    for(int i=0;i<w;i++)
    {
       sum+=a[i]; 
       if(sum>s)
       return false;
    }
    for(int i=w;i<n;i++)
    {
        sum-=a[i-w];
        sum+=a[i];
        if(sum>s)
        return false;
    }
    return true;
}
int main()
{
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int i=1,j=n;
    int ans=0;
    while(i<=j)
    {
        int mid=(i+j)/2;  //windows size
        if(check(a,s,n,mid))
        {
            ans=mid;
          i=mid+1;  
        }
        else
        {
            j=mid-1;
        }
    }
    cout<<ans;

    return 0;
}
