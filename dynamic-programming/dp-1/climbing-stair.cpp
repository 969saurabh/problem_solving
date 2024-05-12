//https://leetcode.com/problems/climbing-stairs/submissions/
class Solution {
public:
    int climbStairs(int n) {
        if(n<2)
        return n;
        else
        {
            int n1=1,n2=2;
            int temp;
            for(int i=3;i<=n;i++)
            {
                temp=n1+n2;
                n1=n2;
                n2=temp;
            }
            return n2;
        }
    }
};