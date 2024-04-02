//https://www.interviewbit.com/problems/matrix-median/
int countElementLess(vector<vector<int>> &a,int key)
{
    int countElement=0;
    for(int i=0;i<a.size();i++)
    {
       
        int low=0,high=a[0].size()-1;
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
int Solution::findMedian(vector<vector<int> > &A) {
    int high=0,low=1;
    for(int i=0;i<A.size();i++)
    {
       high=max(high,A[i][A[0].size()-1]);   
    }
    int count=(A.size()*A[0].size())/2+1;
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int countElement=countElementLess(A,mid);
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