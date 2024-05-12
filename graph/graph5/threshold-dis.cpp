//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/1245504353/
class Solution {
public:
    int numberOfCity(int n,vector<pair<int,int>> adj[],int threshold,int node,int &city)
    {   
        int count=0;
        bool vis[n];
        for(int i=0;i<n;i++)
        vis[i]=false;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,node});
        while(!q.empty())
        {
            int nod=q.top().second;
            int dist=q.top().first;
            
            q.pop();
            if(dist>threshold)
            break;
            if(!vis[nod])
             count++;
             vis[nod]=true;
             if(count>city)
              break;
            for(int i=0;i<adj[nod].size();i++)
            {
                if(!vis[adj[nod][i].first])
                {
                    q.push({adj[nod][i].second+dist,adj[nod][i].first});
                }
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
          adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int city=101;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=numberOfCity(n,adj,distanceThreshold,i,city);
            if(c<=city)
            {
                city=c;
                ans=i;
            }
        }
        return ans;
    }
};
