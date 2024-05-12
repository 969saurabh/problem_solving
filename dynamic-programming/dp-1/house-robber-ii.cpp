//https://leetcode.com/problems/house-robber/submissions/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int t1=0;
        int t2=nums[0];
        int t3=0;
        for(int i=2;i<=n;i++)
        {
           t3=max(t2,nums[i-1]+t1);
           t1=t2;
           t2=t3;
        }
        return t2;
        
    }
};