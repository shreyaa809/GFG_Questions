class Solution {
  public:
    int findMax(vector<vector<int>>&mat,int day,int last,vector<vector<int>>&dp)
    {
        int ans=INT_MIN;
        if (day==0)
        {
            for (int j=0;j<mat[day].size();j++)
            {
                if (j!=last)
                ans=max(ans,mat[day][j]);
                
            }
            return ans;
        }
        int maxi=0;
        if (dp[day][last]!=-1)
            return dp[day][last];
        for (int i=0;i<mat[0].size();i++)
        {
            if (i!=last)
            {
            int points=mat[day][i]+findMax(mat,day-1,i,dp);
            maxi=max(maxi,points);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) 
    {
        // code here
        int n=mat.size();
        int day=n-1;
        int last=mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(last+1,-1));
        return findMax(mat,day,last,dp);
    }
};