//https://leetcode.com/problems/redundant-connection-ii/submissions/1269700379/
class Solution {
public:
    class disjoint{
       int n=0;
       vector<int> parent;
       public:
       //setter function
       void set(int n)
       {
        this->n=n;
        parent.resize(n+1,0);
        for(int i=1;i<=n;i++)
        {
         parent[i]=i;
        }
       }
       //find ultimate parent
       int ultParent(int u)
       {
         if(parent[u]==u)
         return u;
         return parent[u]=ultParent(parent[u]);
       }
       //perform union
       bool Union(int u,int v)
       {
         int ultPt_u=ultParent(u);
         int ultPt_v=ultParent(v);
         
         if(ultPt_u==ultPt_v)
         return false;
         parent[v]=u;
         return true;
       }
       //check is connected
       bool isConnected()
       {
         int count=0;
         for(int i=1;i<=n;i++)
         {
           if(parent[i]==i)
           count++;
         }
         return (count>1)?false:true;
       }
    };
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> pa(n+1,-1);
        for(int i=0;i<edges.size();i++)
        {
            //check if a node has two parent
           if(pa[edges[i][1]]!=-1)
           {
              int p1=pa[edges[i][1]];
              disjoint d2;
              d2.set(n);
              //perform union after deleting ith edge
              for(int j=0;j<n;j++){
                if(j!=i)
                {
                    d2.Union(edges[j][0],edges[j][1]);
                }
              }
              //check if after deleting ith edge all node connected
              //if not connected then we have to delete other edge
              //else we can delete this edge
              if(!d2.isConnected())
              return {edges[p1][0],edges[p1][1]};
              else
              return {edges[i][0],edges[i][1]};

           } 
           pa[edges[i][1]]=i;
        }
        //if cycle is present
        disjoint p;
        p.set(n);
         for(int i=0;i<edges.size();i++)
       {
          bool t=p.Union(edges[i][0],edges[i][1]);
          if(!t)
          return {edges[i][0],edges[i][1]};
       }
      return {};
    }
};