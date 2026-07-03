class Solution {
  public:
    void findAdj(vector<vector<int>>&edges,vector<vector<int>>&adj)
    {
        for (auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        return;
    }
    void Dfs(vector<vector<int>>&adj,vector<bool>&vis,int i,stack<int>&st)
    {
        vis[i]=true;
        for (auto &it:adj[i])
        {
            if (!vis[it])
            Dfs(adj,vis,it,st);
        }
        st.push(i);
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        int n=edges.size();
        vector<vector<int>>adj(V);
       
        findAdj(edges,adj);
        vector<bool>vis(V);
        stack<int>st;
        for (int i=0;i<V;i++)
        {
            if (!vis[i])
            Dfs(adj,vis,i,st);
        }
        vector<int>ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};