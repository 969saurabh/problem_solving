//https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});
        vector<int> vis(n);
        int cost=0;
        while(!q.empty())
        {
          int c=q.top().first;
          int index=q.top().second;
          q.pop();
          if(vis[index]==0)
          {
            cost+=c;
            vis[index]=1;
            for(int i=0;i<n;i++)
            {
                if(i==index)
                continue;
                if(vis[i]==0)
                {
                  int d=abs(points[i][0]-points[index][0])+abs(points[i][1]-points[index][1]);
                  q.push({d,i});
                }
            }
          }
        }
        return cost;

    }
};