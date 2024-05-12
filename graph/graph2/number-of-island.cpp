//https://leetcode.com/problems/number-of-islands/description/
class Solution {
public:
int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};
void dfs(vector<vector<char>>& grid,int r,int c)
{
    for(int i=0;i<4;i++)
    {
        int rn=r+dr[i];
        int cn=c+dc[i];
        if(rn<grid.size()&&cn<grid[0].size())
        if(rn>=0&&cn>=0&&rn<grid.size()&&cn<grid[0].size()&&grid[rn][cn]=='1'){
            grid[rn][cn]='2';
        dfs(grid,rn,cn);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
              if(grid[i][j]=='1')
              {
                count++;
                grid[i][j]='2';
                dfs(grid,i,j);
              }
            }
        }
        return count;
    }
};