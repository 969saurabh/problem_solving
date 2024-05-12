//https://leetcode.com/problems/house-robber-ii/submissions/1254227179/
class Solution {
public:
int Rob(vector<int>& nums,int n) {
        int t1=0;
        int t2=0;
        if(n==nums.size())
         t2=0;
        else
        t2=nums[0];
        int t3=0;
        for(int i=2;i<=n;i++)
        {
           t3=max(t2,nums[i-1]+t1);
           t1=t2;
           t2=t3;
        }
        return t2;  
    }
  /* int robs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>  dp(n,vector<int>(2,INT_MAX));
        dp[0][0]=nums[0];
        dp[0][1]=1;
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);
        if(n>1)
        {
            if(dp[0][0]>nums[1])
            {
                dp[1][0]=dp[0][0];
                dp[1][1]=1;
            }
            else{
            dp[1][0]=nums[1];
            dp[1][1]=0;
            }
        }
        for(int i=2;i<n-1;i++){
            if((dp[i-2][0]+nums[i])>dp[i-1][0])
            {
              dp[i][0]=dp[i-2][0]+nums[i];
              dp[i][1]=dp[i-2][1];
            }
            else if((dp[i-2][0]+nums[i])<dp[i-1][0])
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
            }
            else
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]&dp[i-2][1];
            }
        }
        int val2=dp[n-3][1]==1?dp[n-3][0]-nums[0]+nums[n-1]:dp[n-3][0]+nums[n-1];
        dp[n-1][0]=max(dp[n-2][0],val2);
        return dp[n-1][0];
   }*/
    int rob(vector<int>& nums) {
       int n=nums.size();
       int result=Rob(nums,n);
       int r=Rob(nums,n-1);
       return max(result,r);
    }
};