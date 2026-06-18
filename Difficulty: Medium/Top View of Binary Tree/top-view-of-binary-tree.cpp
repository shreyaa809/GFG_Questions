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
    vector<int> topView(Node *root) 
    {
        // code here
        vector<int>ans;
        if (root==NULL)
        return ans;
        map<int,int>mpp; //col,value
        queue<pair<Node*,int>>q; //col,value
        q.push({root,0});
        while (!q.empty())
        {
            auto p=q.front();
            Node* node=p.first;
            int col=p.second;
            if (mpp.find(col)==mpp.end())
            mpp[col]=node->data;
            q.pop();
            if (node->left)
            q.push({node->left,col-1});
            if (node->right)
            q.push({node->right,col+1});
        }
        for (auto it:mpp)
        {
            ans.push_back(it.second);
            
        }
        return ans;
    }
};