
//https://leetcode.com/problems/course-schedule-ii/submissions/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=prerequisites.size();
        queue<int> q;
       vector<int> indegree(numCourses);
       vector<vector<int>> adj(numCourses);
       vector<int> order;
       for(int i=0;i<n;i++)
       {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
       }
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]==0)
        {
            
            q.push(i);
            order.push_back(i);
            
        }
       }
       while(!q.empty())
       {
         int v=q.front();
         for(int i=0;i<adj[v].size();i++)
         {
            indegree[adj[v][i]]--;
            if(indegree[adj[v][i]]==0)
            {
                q.push(adj[v][i]);
                order.push_back(adj[v][i]);
            }
         }
         q.pop();
       }
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]!=0)
        {
            return {};
        }
       }
      // reverse(order.begin(),order.end());
       return order;
    }
};
