//https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    int i=0,j=pow(10,9)/n;
	    if(m<j)
	    j=m;
	   
	   // if(m==1)
	   // return 1;
	    while(i<=j)
	    {
	        long long mid=(i+j)/2;
	        if(pow(mid,n)==m)
	        return mid;
	        if(pow(mid,n)<m)
	        i=mid+1;
	        else
	        {
	            j=mid-1;
	        }
	    }
	    return -1;
    }
}