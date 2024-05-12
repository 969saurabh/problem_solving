//https://www.geeksforgeeks.org/problems/minimum-edges/1
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            
            
              priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
               bool  vis[n+1];
               for(int i=0;i<=n;i++)
               vis[i]=false;
               q.push(pair<int,int>(0,src));
              unordered_map<int,vector<int>> m1,m2;
               for(int i=0;i<edges.size();i++)
               {
                   m1[edges[i][0]].push_back(edges[i][1]);
                   m2[edges[i][1]].push_back(edges[i][0]);
               }
               while(!q.empty())
               {
                   int node=q.top().second;
                   int cost=q.top().first;
                    q.pop();
                    if(node==dst)
                   return cost;
                    if(!vis[node]){
                     vis[node]=true;
                      for(int i=0;i<m1[node].size();i++)
                      {
                          if(!vis[m1[node][i]])
                          q.push({cost,m1[node][i]});
                      }
                      for(int i=0;i<m2[node].size();i++)
                      {
                          if(!vis[m2[node][i]])
                          q.push({cost+1,m2[node][i]});
                      }
                    }
               }
               return -1;
        }
};