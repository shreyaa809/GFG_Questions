/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void findParent(Node* root,unordered_map<Node*,Node*>&parent)
    {
        if (root==NULL)
        return;
        if (root->left)
        parent[root->left]=root;
        findParent(root->left,parent);
        if (root->right)
        parent[root->right]=root;
        findParent(root->right,parent);
        return;
    }
    Node* findNode(Node* root,int target)
    {
        if (root==NULL||root->data==target)
        return root;
        Node* left=findNode(root->left,target);
        if (left)
        return left;
        return findNode(root->right,target);
        
    }
    int minTime(Node* root, int tar) 
    {
        // code here
        unordered_map<Node*,Node*>parent;
        findParent(root,parent);
        Node* target=findNode(root,tar);;
         int t=0;
         queue<Node*>q;
         q.push(target);
         unordered_map<Node*,bool>vis;
         while (!q.empty())
         {
             int s=q.size();
             
             bool burned=false;
             for (int i=0;i<s;i++)
             {
                 Node* node=q.front();
                 vis[node]=true;
                 q.pop();
                 if (node->left&&!vis[node->left])
                 {
                 q.push(node->left);
                 burned=true;
                 }
                 if (node->right&&!vis[node->right])
                 {
                 q.push(node->right);
                 burned=true;
                 }
                 if (parent[node]&&!vis[parent[node]])
                 {
                 q.push(parent[node]);
                 burned=true;
                 }
             }
             if (burned)
             t++;
         }
         return t;
    }
};