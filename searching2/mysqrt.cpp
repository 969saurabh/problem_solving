//https://leetcode.com/problems/sqrtx/submissions/1198498097/
class Solution {
public:
    int mySqrt(int x) {
        long long l=0,h= min(x,65536);
        int ans=0;
        while(l<=h)
        {
            long long mid=(l+h)/2;
            if((mid*mid)<=x)
            {
              ans=mid;
              l=mid+1;
            }
            
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};