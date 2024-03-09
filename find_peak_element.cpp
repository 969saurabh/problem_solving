//https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(h==0)
        return 0;
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[h]>nums[h-1])
        return h;
        while(l<h)
        {
            int mid=(l+h)/2;
            
            if(nums[mid]<nums[mid+1]) //move to increasing direction
            {
                l=mid+1;
            
            }
            else{
                h=mid;
            }

        }
        return l;
    }
};