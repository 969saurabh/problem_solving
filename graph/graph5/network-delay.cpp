//https://leetcode.com/problems/network-delay-time/submissions/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       bool vis[n+1];
       int mtime=0;
       for(int i=0;i<=n;i++)
       vis[i]=false;
       vector<pair<int,int>> adj[n+1];
       for(int i=0;i<times.size();i++)
       {
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
       q.push({0,k});
       while(!q.empty())
       {
         int time=q.top().first;
         int node=q.top().second;
         if(!vis[node])
         mtime=max(time,mtime);
         vis[node]=true;
         q.pop();
         for(int i=0;i<adj[node].size();i++)
         {
            if(!vis[adj[node][i].first])
            {
                q.push({time+adj[node][i].second,adj[node][i].first});
            }
         }
       }
       for(int i=1;i<=n;i++)
       {
        if(!vis[i])
        return -1;
       }
       return mtime;
    }
};