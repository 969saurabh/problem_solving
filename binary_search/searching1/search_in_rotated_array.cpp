class rotated_array{

public: int search( vector <int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target )
            {
                if(target>=nums[i])
               j=mid-1;
               else
               {
                   if(nums[mid]<nums[i])
                   j=mid-1;
                   else
                   i=mid+1;
               }
            }
            else
            {
                if(target>=nums[i]&&nums[mid]<nums[i])
                j=mid-1;
                else
                {
                    i=mid+1;
                }
            }
        }
        return -1;
    }
};