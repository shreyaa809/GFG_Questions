class Solution {
  public:
   int find (int x,vector<int>&parent)
   {
       if (parent[x]==x)
       return x;
       return parent[x]=find(parent[x],parent);
   }
   
   void Union(int x,int y,vector<int>&parent)
   {
       int x_parent=find(x,parent);
       int y_parent=find(y,parent);
       if (x_parent!=y_parent)
       parent[x_parent]=y_parent;
   }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        vector<int>parent(n+1);
        for (int i=0;i<=n;i++)
        parent[i]=i;
        vector<int>ans;
        for (int i=0;i<queries.size();i++)
        {
            if (queries[i][0]==1)
            {
                Union(queries[i][1],queries[i][2],parent);
                
            }
            else
            {
                ans.push_back(find(queries[i][1],parent));
            }
        }
        return ans;
    }
};