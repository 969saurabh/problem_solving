//https://leetcode.com/problems/get-equal-substrings-within-budget/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> a(s.length());
        for(int i=0;i<s.length();i++)
        {
            a[i]=abs(s[i]-t[i]);  //cost to make equal
        }
        int ans=0;
        int sum=0;
        int i=0,j=0;
        while(j<s.length())
        {
            sum+=a[j];
            while(sum>maxCost&&i<=j)  //if cost > max cost decrease substring size from start
            {
                sum-=a[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};