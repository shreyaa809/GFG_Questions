class Solution {
  public:
    int findKRotation(vector<int> &nums) 
    {
        // Code Here
        int n=nums.size();
        int ans=n,mini=INT_MAX;
        int low=0,high=n-1;
        while (low<=high)
        {
            int mid=high+(low-high)/2;
            if (nums[mid]<mini)
            {
                mini=nums[mid];
                ans=mid;
            }
            if (nums[mid]<=nums[high])
            high=mid-1;
            else
            low=mid+1;
        }
        return ans;
    }
};
