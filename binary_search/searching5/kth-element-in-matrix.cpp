//https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
int countElementLess(int a[][MAX],int key,int n)
{
    int countElement=0;
    for(int i=0;i<n;i++)
    {
       
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(a[i][mid]>key)
            high=mid-1;
            else
            {
                low=mid+1;
            }
        }
        countElement+=low;
    }
    return countElement;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
   int high=0,low=1;
    for(int i=0;i<n;i++)
    {
       high=max(high,mat[i][n-1]);   
    }
    int count=k;
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int countElement=countElementLess(mat,mid,n);
        if(countElement<count)
        low=mid+1;
        else
        {
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}