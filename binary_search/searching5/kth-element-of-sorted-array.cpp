//
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
        if(n>m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
        int low=0;
        int high=n;
        int MAX=1000000009;
  int ans=0;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=k-mid1;
            int l1,l2,r1,r2;
             r1=(mid1>=n)?MAX:arr1[mid1];
              r2=(mid2>=m)?MAX:arr2[mid2];
               l1=((mid1-1)<0)?-1:arr1[mid1-1];
                l2=((mid2-1)<0)?-1:arr2[mid2-1];
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
                    return max(l1,l2);

                }
                ans=max(l1,l2);
        }
        return ans;
}