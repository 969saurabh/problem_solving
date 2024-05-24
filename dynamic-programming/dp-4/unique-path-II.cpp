//https://leetcode.com/problems/unique-paths-ii/submissions/1265186914/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>> path(n,vector<int>(m));
        if(!obstacleGrid[0][0])
        path[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(!obstacleGrid[i][0])
            path[i][0]=path[i-1][0];
        }
         for(int i=1;i<m;i++)
        {
            if(!obstacleGrid[0][i])
            path[0][i]=path[0][i-1];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(obstacleGrid[i][j])
                continue;
                path[i][j]=path[i-1][j]+path[i][j-1];
            }
        }
        return path[n-1][m-1];
        
    }
};