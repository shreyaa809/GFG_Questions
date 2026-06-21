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
    int minValue(Node* root) {
        // code here
        if (!root) return INT_MIN;
        Node* node=root;
        while (root)
        {
            node=root;
            root=root->left;
        }
        return node->data;
    }
};