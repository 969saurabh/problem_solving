//https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1198474854/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        if(j==0)
         return nums[0];
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(mid==0||mid==(nums.size()-1))
            {
                return nums[mid];
            }
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    if(mid%2==0)
                    {
                        j=mid-1;
                    }
                    else
                    {
                        i=mid+1;
                    }
                }
                else
                {
                   if(mid%2==0)
                   {
                       i=mid+1;
                   }
                   else
                   {
                       j=mid-1;
                   }
                }
            }
        }
        return -1;
    }
};