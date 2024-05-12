//https://leetcode.com/problems/number-of-provinces/submissions/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n);
        stack<int> s;
        int count=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
               s.push(i);
               while(!s.empty())
               {
                  int t=s.top();
                  s.pop();
                  vis[t]=1;
                  for(int k=0;k<adj[t].size();k++)
                  {
                    if(!vis[adj[t][k]])
                    {
                        s.push(adj[t][k]);
                    }
                  }
               }
            }
        }
        return count;

    }
};