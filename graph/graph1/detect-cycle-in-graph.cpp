//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<bool> &vis,vector<bool> &visPath,int v){
        vis[v]=true;
        visPath[v]=true;
        for(int i=0;i<adj[v].size();i++)
        {
            if(!vis[adj[v][i]]){
                if(dfs(adj,vis,visPath,adj[v][i])){
                return true;
                }
            }
            else if(visPath[adj[v][i]])
            return true;
            
           //  visPath[v]=false;
        }
        visPath[v]=false;
       return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
      vector<bool> vis(V);
      vector<bool> visPath(V);
      for(int i=0;i<V;i++)
      {
          
         if(!vis[i])
         {
             if(dfs(adj,vis,visPath,i))
             return true;
         }
      }
       return false;
    }
};