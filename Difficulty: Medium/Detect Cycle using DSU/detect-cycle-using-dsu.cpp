class Solution {
  public:
   int find (int x,vector<int>&parent)
   {
       if (x==parent[x])
       return x;
       return parent[x]=find(parent[x],parent);
       
   }
   void Union(int x,int y,vector<int>&parent,vector<int>&rank)
   {
       int x_parent=find(x,parent);
       int y_parent=find (y,parent);
       if (x_parent==y_parent)
       return;
       if (rank[x_parent]<rank[y_parent])
       parent[x_parent]=y_parent;
       else if (rank[x_parent]>rank[y_parent])
       parent[y_parent]=x_parent;
       else
       {
           parent[x_parent]=y_parent;
           rank[y_parent]++;
       }
       return;
   }
    bool detectCycle(int V, vector<int> adj[]) 
    {
        // Code here
        //
        int n=V;
        vector<int>parent(n+1);
        vector<int>rank(n+1,1);
        for (int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for (int u=0;u<n;u++)
        {
            for (int &v:adj[u])
            {
                if (u<v)
                {
                    int u_par=find(u,parent);
                    int v_par=find(v,parent);
                    
                    if (u_par==v_par)
                    return true;
                }
                Union(u,v,parent,rank);
            }
        }
        return false;
        
        
    }
};