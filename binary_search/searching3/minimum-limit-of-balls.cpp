//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    bool checker(vector<int> & nums,int maxOperations,int mid)
    {
        int flag=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            {
                maxOperations-=nums[i]/mid;
                if(nums[i]%mid==0)            //if no. id divisible then it require one less operation [9]=[3,3,3] [7]=[1,3,3] mid=3 
                maxOperations++;
            }
            if(maxOperations<0)
            {
                flag=0;
                break;
            }
        }
        return flag;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i=1,j=INT_MIN;
        
        for(int k=0;k<nums.size();k++)
        {
            j=max(j,nums[k]);
        }
        int ans=j;
        while(i<=j)
        {
            int mid=(i+j)/2;  //assume max penalty
            if(checker(nums,maxOperations,mid))  
            {
                j=mid-1;
                ans=mid;
            }
            else
            i=mid+1;
        }
        return ans;
    }
};