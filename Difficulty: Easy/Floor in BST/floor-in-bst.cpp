/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int x) 
    {
        // code here
        int ans=-1;
        if (root==NULL)
        return ans;
        Node* node=root;
        while (node)
        {
            if (node->data==x)
            return x;
            else if (node->data>x)
            {
                node=node->left;
            }
            else
            {
                ans=node->data;
                node=node->right;
            }
        }
        return ans;
    }
};