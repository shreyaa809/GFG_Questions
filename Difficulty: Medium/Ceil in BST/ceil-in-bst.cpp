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
    int findCeil(Node* root, int x) 
    {
        // code here
        if (root==NULL)
        return -1;
        Node* node=root;
        int ans=-1;
        while (node)
        {
            if (node->data==x)
            return x;
            if (node->data>x)
            {
                ans=node->data;
                node=node->left;
            }
            else if (node->data<x)
            node=node->right;
        }
        return ans;
    }
};
