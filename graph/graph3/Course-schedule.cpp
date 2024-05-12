//https://leetcode.com/problems/course-schedule/submissions/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        queue<int> q;
       vector<int> indegree(numCourses);
       vector<vector<int>> adj(numCourses);
       for(int i=0;i<n;i++)
       {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
       }
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]==0)
        {
            
            q.push(i);
            
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
            }
         }
         q.pop();
       }
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]!=0)
        {
            return false;
        }
       }
       return true;
    }
};
