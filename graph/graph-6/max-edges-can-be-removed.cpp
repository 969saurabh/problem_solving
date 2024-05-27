//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/submissions/1269819994/
class Solution {
public:
    class Disjoint{
       private:
       int n;
       vector<int> parent,size;
       public:
       Disjoint(int n)
       {
        this->n=n;
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
       }
       int ultParent(int u)
       {
         if(parent[u]==u)
         return u;
         return parent[u]=ultParent(parent[u]);
       }
       bool Union(int u,int v)
       {
         int ultParent_u=ultParent(u);
         int ultParent_v=ultParent(v);
         if(ultParent_u==ultParent_v)
         return false;
         if(size[ultParent_u]>size[ultParent_v])
         {
            size[ultParent_u]+=size[ultParent_v];
            parent[ultParent_v]=ultParent_u;
         }
         else
         {
             size[ultParent_v]+=size[ultParent_u];
            parent[ultParent_u]=ultParent_v;
            
         }
         return true;
       }
       bool isConnected()
       {
          int c=0;
          for(int i=1;i<=n;i++)
          {
            cout<<parent[i]<<" ";
             if(parent[i]==i)
             c++;
          }
          cout<<endl;
          return (c>1)?false:true;
       }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Disjoint alice(n),bob(n);
        int count=0;
       //union of edges which can be traverse by both alice and bob
        for(int i=0;i<edges.size();i++)
        {
           if(edges[i][0]==3)
           {
             bool t=alice.Union(edges[i][1],edges[i][2]);
            //both node is already part of same component
             if(!t)
             {
                count++;
             }
             bob.Union(edges[i][1],edges[i][2]);
           }
        }
        //union of rest of edges
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            {
                bool t=alice.Union(edges[i][1],edges[i][2]);
                //both node is already part of same component
                if(!t)
                {
                   count++;
                }
            }
            if(edges[i][0]==2)
            {
                 bool t=bob.Union(edges[i][1],edges[i][2]);
                if(!t)
                {
                   count++;
                }
            }
        }
        //if all node can not be traverse
        if((!alice.isConnected())||(!bob.isConnected()))
        return -1;
        return count;
    }
};