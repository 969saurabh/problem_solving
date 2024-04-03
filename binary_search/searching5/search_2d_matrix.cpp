//https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int sr=0,er=matrix.size()-1;
       int low=0,high=matrix[0].size()-1;
     while(sr<er)
     {
        int mid=(sr+er)/2;
        if(matrix[mid][0]==target)
        return true;
        else if(target>matrix[mid][0])
        {
           if(target<=matrix[mid][high])
           {
            sr=mid;
            er=mid;
           }
           else
           sr=mid+1;
        }
     
        else
        er=mid-1;
     }
   
     while(low<=high)
     {
        int mid=low+(high-low)/2;
        if(matrix[sr][mid]==target)
        return true;
        else if(matrix[sr][mid]>target)
        high=mid-1;
        else
        low=mid+1;
     }
return false;
        
    }
};