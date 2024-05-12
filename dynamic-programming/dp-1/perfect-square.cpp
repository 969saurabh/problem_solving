//https://leetcode.com/problems/perfect-squares/submissions/
class Solution {
public:
    int numSquares(int n) {
        vector<int> a(n+1);
        for(int i=0;i<=n;i++)
        {
            a[i]=i;
        }
        int num=2;
        while((num*num)<=n)
        {
            int t=num*num;
          for(int i=t;i<=n;i++)
          {
            a[i]=min(a[i],a[i-t]+1);
          }
          num++;
        }
      //  cout<<a[n];
        return a[n];
    }
};