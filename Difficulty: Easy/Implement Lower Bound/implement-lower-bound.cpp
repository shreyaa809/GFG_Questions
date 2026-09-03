class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) 
    {
        // code here
        int n=arr.size();
        int low=0,high=n-1;
        int ans=n;
        while (low<=high)
        {
            int mid=high+(low-high)/2;
            if (arr[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if (arr[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};
