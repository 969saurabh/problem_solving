//https://www.interviewbit.com/problems/valid-path/
bool isnotInside(int x,int y,int r,vector<int> &e,vector<int> &f)
{
    
    for(int i=0;i<e.size();i++)
    {
       int d=(pow(e[i]-x,2)+pow(f[i]-y,2));
        if(d<=(r*r))
        return false;
    }
    return true;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
   vector<vector<bool>> visited(A+1,vector<bool>(B+1,false));
   queue<pair<int,int>> q;
   q.push({0,0});
   int dx[]={1,1,1,-1,-1,-1,0,0};
   int dy[]={1,-1,0,1,-1,0,1,-1};
   visited[0][0]=true;
   if(A==0&&B==0)
   return "YES";
   while(!q.empty())
   {
       for(int i=0;i<8;i++)
       {
           int x=q.front().first+dx[i];
           int y=q.front().second+dy[i];
           if(x>=0&&y>=0&&x<=A&&y<=B&&(!visited[x][y])&&(isnotInside(x,y,D,E,F)))
           {
               
               q.push({x,y});
               visited[x][y]=true;
               if(x==A&&y==B)
               return "YES";
           }
       }
       q.pop();
   }
   return "NO";
}
