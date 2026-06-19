/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isLeave(Node* root)
    {
        return (!root->left&&!root->right);
    }
    void paths(Node* root,vector<vector<int>>&ans,vector<int>&arr)
    {
        if (root==NULL)
        return;
        arr.push_back(root->data);
        if (isLeave(root))
        {
            ans.push_back(arr);
            
        }
        if (root->left)
        {
        paths(root->left,ans,arr);
        arr.pop_back();
        }
        if (root->right)
        {
        paths(root->right,ans,arr);
        arr.pop_back();
        }
       
    }
    vector<vector<int>> Paths(Node* root) 
    {
        // code here
        vector<vector<int>>ans;
        if (root==NULL)
        return ans;
        if (isLeave(root))
        return {{root->data}};
        vector<int>arr;
        paths(root,ans,arr);
        return ans;
    }
};