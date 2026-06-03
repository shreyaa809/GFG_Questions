class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& nums) 
    {
        //  code here
        int n=nums.size();
        vector<int>nse(n);
        stack<int>st;
        for (int i=n-1;i>=0;i--)
        {
            while(!st.empty()&& nums[i]<=st.top())
            st.pop();
            if (st.empty())
            nse[i]=-1;
            else
            nse[i]=st.top();
            st.push(nums[i]);
        }
        return nse;
    }
};