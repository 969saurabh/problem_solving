//https://leetcode.com/problems/unique-paths/submissions/1265181039/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            path[0][i]=1;
        }
        for(int i=1;i<n;i++)
        {
          path[i][0]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                path[i][j]=path[i-1][j]+path[i][j-1];
            }
        }
        return path[n-1][m-1];
    }
};