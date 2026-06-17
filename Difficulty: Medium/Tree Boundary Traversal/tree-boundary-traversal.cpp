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
       if (!root->left&&!root->right)
       return true;
       return false;
    }
    void addLeft(Node* root,vector<int>&ans)
    {
        root=root->left;
        while (root)
        {
            if (!isLeave(root))
            ans.push_back(root->data);
            if (root->left)
            root=root->left;
            else
            root=root->right;
        }
    }
    void addLeave(Node* root,vector<int>&ans)
    {
        if (root==NULL)
        return;
        if (isLeave(root))
        ans.push_back(root->data);
        if (root->left)
        addLeave(root->left,ans);
        if (root->right)
        addLeave(root->right,ans);
        
    }
    
    void addRight(Node* root,vector<int>&ans)
    {
        root=root->right;
        vector<int>res;
        while (root)
        {
            if (!isLeave(root))
            res.push_back(root->data);
            if (root->right)
            root=root->right;
            else
            root=root->left;
        }
        reverse(res.begin(),res.end());
        ans.insert(ans.end(),res.begin(),res.end());
    }
    vector<int> boundaryTraversal(Node *root) 
    {
        //code here
       
        vector<int>ans;
        if (root==NULL)
        return ans;
        if (!isLeave(root))
        ans.push_back(root->data);
        addLeft(root,ans);
        addLeave(root,ans);
        addRight(root,ans);
        return ans;
    }
};