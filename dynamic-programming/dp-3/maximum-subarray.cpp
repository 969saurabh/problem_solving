//https://leetcode.com/problems/maximum-subarray/submissions/1181144647/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int ma=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum<0)
            {
               sum=nums[i]; 
            }
            else
            {
                sum+=nums[i];
            }
           ma=max(ma,sum);
        }
        return ma;
    }
};