//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]>nums[l])
            {
              if(target<nums[mid]&&target>=nums[l])
              h=mid-1;
              else
              {
                  l=mid+1;
              }
            }
            else if(nums[mid]<nums[l])
            {
                if(target<nums[mid]||target>=nums[l])
                h=mid-1;
                else
                l=mid+1;
            }
            else  //handle ambiguous condition eg[1,1,0,1,1,1,1] [1,1,1,1,0,1]
            {
                while(l<=h)
                {
                    if(nums[l]==target)
                    return true;
                    l++;
                }
            }
        }
        return false;
    }
};