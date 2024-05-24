//https://leetcode.com/problems/minimum-path-cost-in-a-grid/submissions/1265534907/
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> minCost(n,vector<int> (m));
        //cost of 1st row will be same as grid val
        for(int i=0;i<m;i++)
        {
           minCost[0][i]=grid[0][i];
        }
        //finding minimum cost to reach each (i,j) in grid
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int t=INT_MAX;
                //check each col of (i-1)th row to find min cost  
                for(int k=0;k<m;k++)
                {
                   t=min(t,moveCost[grid[i-1][k]][j]+minCost[i-1][k]);
                }
                minCost[i][j]=t+grid[i][j];
            }
        }
         int mCost=INT_MAX;
         //check for min cost in last row
         for(int i=0;i<m;i++)
         {
            mCost=min(mCost,minCost[n-1][i]); 
         }
         return mCost;
    }
   
};