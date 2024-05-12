//https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/submissions/1244938487/
/*class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> ans(n,-1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
      q.push({0,0});
     // vector<bool> vis(n);
      while(!q.empty())
      {
         pair<int,int> t=q.top();
         q.pop();
         if(t.first<disappear[t.second]&&(ans[t.second]==-1||ans[t.second]>t.first))
         {
           // vis[t.second]=true;
            ans[t.second]=t.first;
            for(int i=0;i<adj[t.second].size();i++)
            {
                if(ans[adj[t.second][i].first]==-1)
                q.push({t.first+adj[t.second][i].second,adj[t.second][i].first});
            }
         }
      }
      return ans;
    }
};*/
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> dist(n, INT_MAX);
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        // vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            pair<int, int> P = pq.top();
            pq.pop();
            int wt = P.first;
            int parent = P.second;
            // if(visited[parent]) continue ;
            // visited[parent] = true;
            if(wt > dist[parent]) continue ;
            for(int i = 0; i < adj[parent].size(); i++){
                int child = adj[parent][i].first;
                int childWt = adj[parent][i].second;
                if(wt + childWt < dist[child] && wt + childWt < disappear[child]){
                    dist[child] = wt + childWt;
                    pq.push({dist[child], child});
                }
            }
        }
        for(int i = 0; i < dist.size(); i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};