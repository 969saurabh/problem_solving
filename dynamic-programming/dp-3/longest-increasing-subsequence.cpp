//https://leetcode.com/problems/longest-increasing-subsequence/submissions/1249978937/
class Solution {
public:
 int searchIndex(vector<int> a,int key)
   { int i=0;
     int j=a.size()-1;
     int index=j;
     while(i<=j)
     {
        int mid=i+(j-i)/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]>key){
            index=mid;
            j=mid-1;
        }
        else
        i=mid+1;
     }
     return index;
   }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        int top=0;
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]>sub[top])
          {
            sub.push_back(nums[i]);
            top++;
          }
          else
          {
             sub[searchIndex(sub,nums[i])]=nums[i];
          }
        }
        return top+1; 
    }
};