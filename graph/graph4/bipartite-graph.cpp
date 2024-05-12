//https://leetcode.com/problems/is-graph-bipartite/submissions/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<int> setStatus(n);
       queue<pair<int,int>> q;
       for(int i=0;i<graph.size();i++)
       {
        if(setStatus[i]==0)
        {
            q.push({i,1});
            setStatus[i]=1;
        while(!q.empty())
        {
          int t=q.front().first;
          int s=q.front().second;
          s=(s==1)?2:1;
          q.pop();
          for(int k=0;k<graph[t].size();k++)
          {
            if(setStatus[graph[t][k]]!=0&&setStatus[graph[t][k]]!=s)
            {
                return false;
            }
            if(setStatus[graph[t][k]]==0)
            {
                q.push({graph[t][k],s});
                setStatus[graph[t][k]]=s;
            }
          }
        }
        }
       }
       return true;
    }
};