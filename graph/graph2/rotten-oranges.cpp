//https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
   int dir[4]={1,0,-1,0};
   int d[4]={0,1,0,-1};
   class triplet{
     public: int r,c,time;
     triplet(int r,int c,int time)
     {
       this->r=r;
       this->c=c;
       this->time=time;
     }
   };
   int rott(vector<vector<int>> &grid,queue<triplet> &q)
   {
    int mtime=0;
    int n=grid.size();
    int m=grid[0].size();
     while(!q.empty())
     {
        for(int i=0;i<4;i++)
        {
             int row=q.front().r+dir[i];
             int col=q.front().c+d[i];
             int t=q.front().time+1;
             if(row>=0&&col>=0&&row<n&&col<m&&grid[row][col]==1)
             {
               q.push(triplet(row,col,t));
               grid[row][col]=2;
               mtime=max(mtime,t);
             }
        }
        q.pop();
     }
     return mtime;
   }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<triplet> info;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    info.push(triplet(i,j,0));
                }
            }
        }
        int time=rott(grid,info);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};