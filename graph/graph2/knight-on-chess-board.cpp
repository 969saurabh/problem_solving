//https://www.interviewbit.com/problems/knight-on-chess-board/
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<vector<int>> q;
    int y[8]={2,2,-2,-2,1,1,-1,-1};
    int x[8]={1,-1,1,-1,-2,2,-2,2};
    q.push({C,D,0});
    vector<vector<int>> visited(A+1,vector<int>(B+1));
    visited[C][D]=1;
    if(C==E&&D==F)
    return 0;
    while(!q.empty())
    {
        for(int i=0;i<8;i++)
        {
            
            int ix=q.front()[0]+x[i];
            int iy=q.front()[1]+y[i];
            if(ix==E&&iy==F)
            {
                
                return q.front()[2]+1;
            }
            if(ix>0&&iy>0&&ix<=A&&iy<=B&&visited[ix][iy]==0)
            {
                q.push({ix,iy,q.front()[2]+1});
                visited[ix][iy]=1;
            }
        }
        q.pop();
    }
    return -1;
}