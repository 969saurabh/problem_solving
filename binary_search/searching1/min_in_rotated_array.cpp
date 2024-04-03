//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
      
        
         while(i<j)
         {   
               int mid=(i+j)/2;
               if(nums[mid]>=nums[i])  //mid in left subarray
               {
                   if(nums[i]>nums[j])  //array is rotated hence min element is in right subarray
                   i=mid+1;
                   else       //array is not rotated.
                   j=mid-1;
               }
               else
               {
                  j=mid;//j may be required index
                  
               }
         }   
         return nums[i];    
    }
};