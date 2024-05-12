//https://www.geeksforgeeks.org/problems/friends-pairing-problem5425/1
class Solution
{
public:
int mod=1000000007;
   /* int countFriendsPairings(int n) 
    { 
        // code here
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long x=(long long)(i-1);
            long long y=(long long)(dp[i-2]);
            long long t=x*y+((long long)dp[i-1]);
           dp[i]=t%mod;
        }
        return dp[n];
    }*/
    int countFriendsPairings(int n) 
    { 
        // code here
       int t1=1,t2=1;
        for(int i=2;i<=n;i++)
        {
            long long x=(long long)(i-1);
            long long y=(long long)(t2);
            long long t=x*y+((long long)(t1));
            t2=t1;
            t1=t%mod;
        }
        return t1;
    }
};    