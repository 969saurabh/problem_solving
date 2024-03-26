//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int  m=nums2.size();
        int med=(n+m+1)/2;
        if(n>m)
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0;
        int high=n;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=med-mid1;
            int l1,l2,r1,r2;
             r1=(mid1>=n)?INT_MAX:nums1[mid1];
              r2=(mid2>=m)?INT_MAX:nums2[mid2];
               l1=((mid1-1)<0)?INT_MIN:nums1[mid1-1];
                l2=((mid2-1)<0)?INT_MIN:nums2[mid2-1];
                if(l1>r2)
                {
                    high=mid1-1;
                }
               else if(l2>r1)
                {
                    low=mid1+1;
                }
                else
                {
                    if((m+n)%2!=0)
                    return max(l1,l2);
                    else
                    return (double(max(l1,l2)+min(r1,r2)))/2.0;

                }
        }
        return -1;
    }
};