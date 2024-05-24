//https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/submissions/1264337747/
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
     int n=nums.size();
     vector<vector<int>> dp(n+1,vector<int>(target+1));
     for(int i=0;i<n;i++)
     {
        for(int j=1;j<=target;j++)
        {
            if(j<nums[i])
            {
                dp[i+1][j]=dp[i][j];
            }
          else if(j==nums[i])
          {
            dp[i+1][j]=max(1,dp[i][j]);
          }
          else if(dp[i][j-nums[i]]==0){
             dp[i+1][j]=dp[i][j];
          }  
          else if(dp[i][j-nums[i]]!=0)
          {
            dp[i+1][j]=max(dp[i][j],dp[i][j-nums[i]]+1);
          }   
        }
        cout<<dp[i+1][target]<<" ";
     }  
     if(dp[n][target]==0)
     return -1;
     return dp[n][target];      
    }
};