//https://leetcode.com/problems/nth-magical-number/
//https://www.geeksforgeeks.org/find-the-nth-term-divisible-by-a-or-b-or-c/
class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {
        int mod=1e9+7;
        long long ans=0;
        if(n==1)
        return min(a,b);
        else
        {
            long l=min(a,b);
            long lc=lcm(a,b);
           long long h=n*l;
            while(l<=h)
            {
                long long mid=l+(h-l)/2;
                long long count=(mid/a)+(mid/b)-(mid/lc);
                if(count==n)
                {
                   if(mid%a==0||mid%b==0){
                      ans=mid;
                      return mid%mod;
                   }
      
                   else
                   {
                      h=mid-1;
                   }
                }
                else if(count>n)
                {
                    h=mid-1;
                }
                else
                {
                    //break;
                    l=mid+1;
                }

            }
        }
        return -1;
    }
};