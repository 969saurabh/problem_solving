//https://www.geeksforgeeks.org/problems/rotation4723/1
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    int i=0,j=n-1;
	    while(i<=j)
	    {
	        int mid=(i+j)/2;
	        if(arr[i]<=arr[j])
	        {
	        return i;
	        }
	       if(arr[j]<arr[j-1])
	       return j;
	        if(arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1])
	        return mid;
	        else if(arr[mid]>=arr[i])
	        i=mid+1;
	        else
	        j=mid-1;
	    }
	    return 0;
	}

};