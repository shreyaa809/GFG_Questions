class Solution {
  public:
    void findAdj(int V,vector<vector<int>>&edges,vector<vector<int>>&adj)
    {
        for (auto it:edges)
        {
            int u=it[0]; int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        // Code here
        
        vector<vector<int>>adj(V);
        findAdj(V,edges,adj);
        vector<int>vis(V,-1);
        queue<pair<int,int>>q;
        for (int i=0;i<V;i++){
            if (vis[i]==-1)
            {
        
        q.push({i,-1});
        
        vis[i]=0;
        
        while (!q.empty())
        {
            int p=q.front().first;
            int r=q.front().second;
            
            q.pop();
            
            for (auto neighbor:adj[p])
            {
                if (vis[neighbor]==-1)
                {
                q.push({neighbor,p});
                vis[neighbor]=p;
                    
                }
                else if (neighbor!=r)
                {
                    return true;                
                }
            }
        }}}
        return false;
    }
};