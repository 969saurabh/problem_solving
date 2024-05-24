//https://leetcode.com/problems/maximum-product-subarray/submissions/1194852540/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int t1=1,t2=1;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans=max(ans,0);
                t1=1;
                t2=1;
                flag=0;
            }
            else
            {
                if(t1>0)
                {
                    t1=t1*nums[i];
                    if(flag==1)
                    {
                        t2=t2*nums[i];
                        ans=max(ans,t2);
                    }
                }
                else
                {
                    flag=1;
                    t1=t1*nums[i];
                    t2=t2*nums[i];
                    ans=max(ans,t2);
                }
                ans=max(ans,t1);
            }
        }
        return ans;
    }
};