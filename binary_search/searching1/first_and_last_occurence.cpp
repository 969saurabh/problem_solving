//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int flag=0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]==target) //check if target present 
            flag=1;
            if(nums[mid]>=target)
            j=mid-1;
            else
            {
                i=mid+1;
            }
        }
        int a=j+1;
        if(flag==0) //return target not present
        return {-1,-1};
        i=0,j=nums.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>target)
            j=mid-1;
            else
            {
                i=mid+1;
            }
        }
    
            return {a,i-1};
       
    }
};