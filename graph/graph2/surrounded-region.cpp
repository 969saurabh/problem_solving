//https://leetcode.com/problems/surrounded-regions/description/
class Solution {
public:
   int dir[4]={1,0,-1,0};
    int direc[4]={0,1,0,-1};
    void notSurrounded(vector<vector<char>>& board,int i,int j)
    {
        board[i][j]='#';
        for(int k=0;k<4;k++)
        {
           int l=i+dir[k];
           int m=j+direc[k];
            if(l>=0&&m>=0&&l<board.size()&&m<board[0].size()&&board[l][m]=='O')
           {
               notSurrounded(board,l,m);
           }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                notSurrounded(board,i,0);
            }
            if(board[i][m-1]=='O')
            {
                notSurrounded(board,i,m-1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                notSurrounded(board,0,i);
            }
            if(board[n-1][i]=='O')
            {
                notSurrounded(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(board[i][j]=='O')
                board[i][j]='X';
                if(board[i][j]=='#')
                board[i][j]='O';
               
            }
        }
    }
};