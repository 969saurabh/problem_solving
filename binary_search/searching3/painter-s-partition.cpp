//https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTabValue=SUBMISSION
bool check(vector<int> &boards,int k,int mid)
{
    int c=1;
    int sum=0;
    for(int i=0;i<boards.size();i++)
    {
       sum+=boards[i];
       if(sum>mid)
       {
           sum=boards[i];
           c++;
       }
       if(c>k||boards[i]>mid)
       return 0;
    }
    return 1;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    long long i=1,j=0;
    int ans=-1;
    for(int i=0;i<boards.size();i++)
    {
        j+=boards[i];
    }
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(check(boards,k,mid))
        {
            j=mid-1;
            ans=mid;
        }
        else
        {
            i=mid+1;
        }

    }
    return ans;
}