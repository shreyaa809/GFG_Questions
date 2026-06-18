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
    vector<int> bottomView(Node *root) 
    {
        // code here
        vector<int>ans;
        if (root==NULL)
        return ans;
        map<int,pair<int,int>>mpp; //col,y,value
        queue<pair<Node*,pair<int,int>>>q;  //node,col,y
        q.push({root,{0,0}});
        while (!q.empty())
        {
            auto p=q.front();
            Node* node=p.first;
            int y=p.second.second;
            int col=p.second.first;
            if (mpp.find(col)==mpp.end())
            mpp[col]={y,node->data};
            else if (mpp.find(col)!=mpp.end()&&(mpp[col].first<=y))
            mpp[col]={y,node->data};
            q.pop();
            if (node->left)
            q.push({node->left,{col-1,y+1}});
            if (node->right)
            q.push({node->right,{col+1,y+1}});
        }
        for (auto it:mpp)
        {
            ans.push_back(it.second.second);
        }
        return ans;
    }
};