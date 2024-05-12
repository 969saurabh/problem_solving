//https://leetcode.com/problems/find-if-path-exists-in-graph/
class Solution {
public:
    void path(vector<vector<int>>& edges,vector<vector<int>> &adj)
    {
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
        return true;
        queue<int> s;
        vector<int> visited(n);
        vector<vector<int>> adj(n);
        path(edges,adj);
        s.push(source);
        visited[source]=1;
       while(!s.empty())
       {
          int j=s.front();
          for(int i=0;i<adj[j].size();i++){
                if(adj[j][i]==destination)
                return true;
                if(visited[adj[j][i]]==0){
                visited[adj[j][i]]=1;
                s.push(adj[j][i]);
                }
             }
          s.pop();
       }
       return false;
    }
};
