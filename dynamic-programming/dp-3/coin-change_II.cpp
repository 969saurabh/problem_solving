//https://leetcode.com/problems/coin-change-ii/submissions/1264197361/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> ways(amount+1);
        ways[0]=1;
        for(int i=0;i<coins.size();i++)
        {   
            for(int j=coins[i];j<=amount;j++)
            {
                ways[j]=ways[j]+ways[j-coins[i]];
            }
        }
        return ways[amount];
    }
    
};