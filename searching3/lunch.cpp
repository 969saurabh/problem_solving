/*Deepthi loves cruises. She is going to visit the Caribbean on a Cruise. So, she thought of providing everyone who is traveling with her with lunch as well. Each food item is denoted by an integer ID. A lunch box contains exactly A food items. She has a list of food items with her denoted by an integer array B. She asked you to tell her the maximum number of lunchboxes she can prepare.

Note:
A lunch box can contain multiple same kinds of food items but the content of each lunch box should be the same.
Example Input
Input 1:
A = 3, B = [1, 2, 3, 2, 6, 1, 3]
Input 2:
A = 4, B = [1, 3, 1, 3, 10, 3, 6, 6, 13]
Example Output
Output 1:
2
Output 2:
1
Example Explanation
Explanation 1:
She can choose the content to be [1, 2, 3] and prepare 2 luchboxes
Explanation 2:
She can choose the content to be [1, 3, 3, 3]
 */
#include <iostream>
#include<vector>
#include<map>
using namespace std;
bool check(map<int,int> m,int a,int l)
{
    for(auto x:m)
    {
        if(x.second>=l)
        {
            a=a-(x.second)/l;
        }
    }
    return a<=0;
    
}
int main()
{
    int a,n;
    cin>>a>>n;
    vector<int> item(n);
    int i=1,j=0;
    for(int i=0;i<n;i++)
    {
        cin>>item[i];
        j=max(item[i],j);      //maximum lunch can made
    }
    map<int,int> m;
    for(int i=0;i<n;i++)  //count no. of each item
    {
        m[item[i]]++;
    }
    int ans=0;
    while(i<=j)
    {
        int mid=i+(j-i)/2; //assumed lunch
        if(check(m,a,mid))
        {
            i=mid+1;
            ans=mid;
        }
        else
        j=mid-1;
        
    }
    cout<<ans<<endl;
    return 0;
}
