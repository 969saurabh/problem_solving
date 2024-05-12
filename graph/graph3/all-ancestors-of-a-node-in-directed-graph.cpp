//https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/submissions/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestor(n);
        vector<vector<int>> neighbour(n);
        vector<int> indegree(n);
        queue<int> q;
        for(int i=0;i<edges.size();i++)
        {
           indegree[edges[i][1]]++;
           neighbour[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<set<int>> ances(n);
        while(!q.empty())
        {
            set<int> s;
            int fron=q.front();
            q.pop();
            for(int i=0;i<neighbour[fron].size();i++)
            {
                indegree[neighbour[fron][i]]--;
                ances[neighbour[fron][i]].insert(ances[fron].begin(),ances[fron].end());
                ances[neighbour[fron][i]].insert(fron);
                if(indegree[neighbour[fron][i]]==0)
                q.push(neighbour[fron][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            ancestor[i].insert(ancestor[i].begin(),ances[i].begin(),ances[i].end());
        }
       return ancestor;
    }
};