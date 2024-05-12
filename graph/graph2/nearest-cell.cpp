//https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
class Solution 
{ 
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code heree
	     int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> result(n,vector<int> (m));
	   
	    int dx[]={1,-1,0,0};
	    int dy[]={0,0,1,-1};
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	            }
	    }
	    }
	    int x,y,z;
	    while(!q.empty())
	    {
	        for(int i=0;i<4;i++)
	        {
	           x=q.front().first.first+dx[i];
	            y=q.front().first.second+dy[i];
	           
	           if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y]==0)
	           {
	                z=q.front().second+1;
	               q.push({{x,y},z});
	               grid[x][y]=1;
	               result[x][y]=z;
	           }
	        }
	        q.pop();
	    }
	    return result;
	}
};
