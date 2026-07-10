class Solution {
  public:
    void findAdj(int V, vector<vector<int>>&edges,vector<vector<int>>&adj)
    {
        for (auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        return;
    }
    void findIndegree(int V, vector<vector<int>>&adj,vector<int>&inD,int u)
    {
        for (auto &it:adj[u])
        {
            inD[it]++;
        }
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        //i havee to do using bfs->kahn's algo->indegree, queue use hoga
        vector<vector<int>>adj(V);
       
        findAdj(V,edges,adj);
        vector<int>inD(V);
        for (int i=0;i<V;i++)
        findIndegree(V,adj,inD,i);
        
        queue<int>q;
        vector<int>ans;
        for (int i=0;i<V;i++)
        {
            if (inD[i]==0)
            q.push(i);
        }
        
        while (!q.empty())
        {
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for (auto &it:adj[curr])
            {
                inD[it]--;
                if (inD[it]==0)
                q.push(it);
            }
        }
        return ans;
        
    }
};