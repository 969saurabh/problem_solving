//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1201857927/
class Solution {
public:
    bool helper(vector<int> &bloomDay,int m,int k,int mid)
    {
        int count=0;
        int b=0;
       for(int i=0;i<bloomDay.size();i++)
       {
        if(bloomDay[i]<=mid)
        {
            count++;
            if(count==k)
            {
              b++;
              count=0;
            }
        }
        else
        {
            count=0;
        }
       }
       return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int i=INT_MAX,j=INT_MIN;
     /*  if((m*k)>bloomDay.size())
       return -1;*/
       for(int k=0;k<bloomDay.size();k++) 
       {
         j=max(j,bloomDay[k]);  //max days taken to bloom all flower
         i=min(i,bloomDay[k]);  //min days taken to bloom atleast one flower
       }
       int ans=-1;
       while(i<=j)
       {
        int mid=(i+j)/2;  //assume days in which bouque can be made 
        if(helper(bloomDay,m,k,mid))  //check if required bouque can be made in mid no. of days
        {
          ans=mid;
          j=mid-1;
        }
        else
        {
            i=mid+1;
        }
       }
       return ans;
    }
};