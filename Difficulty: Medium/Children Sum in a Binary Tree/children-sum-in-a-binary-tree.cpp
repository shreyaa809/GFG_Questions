/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isLeaf(Node* root)
    {
        return (!root->left&&!root->right);
    }
    bool isSUM(Node* node,int left,int right)
    {
        if (node==NULL)
        return true;
        if (node->left)
            left=node->left->data;
            else
            left=0;
            if (node->right)
            right=node->right->data;
            else
            right=0;
            if ((node->data!=left+right)&&(!isLeaf(node)))
            return false;
            
            return isSUM(node->left,left,right)&&isSUM(node->right,left,right);
    }
    bool isSumProperty(Node *root) 
    {
        // code here4
        if (root==NULL)
        return true;
        int left,right;
        
        return isSUM(root,left,right);
    }
};