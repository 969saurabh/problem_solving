//https://www.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
public:
  
     bool check(vector<int> &stall ,int d,int n,int k)
     {
         int m=0;
         for(int i=0;i<n;i++)
         {
             if((stall[i]-stall[m])>=d)
             {
                 k--;
                 m=i;
                 
             }
         }
         if(k<=0)
         return true;
         else
         return false;
         
     }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int i=1,j=stalls[n-1]/(k-1);
        int ans=0;
        while(i<=j)  //search space possible gap b/w cow
        {
            int mid=(i+j)/2;
            if(check(stalls,mid,n,k-1)) //check min gap possible
            {
                i=mid+1;
                ans=mid;
            }
            else
            j=mid-1;
        }
        return ans;
    }
};