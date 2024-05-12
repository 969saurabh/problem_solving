//https://leetcode.com/problems/decode-ways/submissions/1254640165/
class Solution {
public:
    int decoding(string &s,int index,vector<int> &dp)
    {
        if(index==s.length())
         return 1;
         if(index>s.length()||s[index]=='0')
         return 0;
         if(dp[index]!=-1)
         return dp[index];
        int x=decoding(s,index+1,dp);
        int y=0;
        if(s[index]<'2'||(index<s.length()-1&&s[index]=='2'&&s[index+1]<'7'))
         y=decoding(s,index+2,dp);
        return dp[index]=x+y;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return decoding(s,0,dp);
    }
};