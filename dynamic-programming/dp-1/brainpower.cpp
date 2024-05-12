//https://leetcode.com/problems/solving-questions-with-brainpower/submissions/1250547086/
class Solution {
public:
   /******************************************************************************
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--)
        {
            long long val=(questions[i][1]+i+1)>=n?0:dp[questions[i][1]+1+i];
           dp[i]=max(dp[i+1],val+questions[i][0]);
        }
        return dp[0];
    }
**********************************************************************************/

/*********************************************************************************
    
    long long mostPoints(vector<vector<int>> &questions,int i)
    {
        if(i>=questions.size())
        return 0;
        long long  x=questions[i][0]+mostPoints(questions,i+questions[i][1]+1);
        long long y=mostPoints(questions,i+1);
        return max(x,y);
    }
    long long mostPoints(vector<vector<int>>& questions){
         return mostPoints(questions,0);
    }

**********************************************************************************/
    vector<long long> dp;
    long long mostPoints(vector<vector<int>> &questions,int i)
    {
        if(i>=questions.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        long long  x=questions[i][0]+mostPoints(questions,i+questions[i][1]+1);
        long long y=mostPoints(questions,i+1);
        return dp[i]=max(x,y);
    }
    long long mostPoints(vector<vector<int>>& questions){
        dp.resize(questions.size(),-1);
         return mostPoints(questions,0);
    }
};