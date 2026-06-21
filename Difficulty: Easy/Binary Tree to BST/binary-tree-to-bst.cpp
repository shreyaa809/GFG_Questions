/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void findArr(Node* root,vector<int>&arr)
    {
        if (root==NULL) return;
        findArr(root->left,arr);
        arr.push_back(root->data);
        findArr(root->right,arr);
        return;
    }
    void tobst(Node* root,vector<int>&arr,int& i)
    {
        if (root==NULL) return;
        tobst(root->left,arr,i);
        root->data=arr[i++];
        tobst(root->right,arr,i);
    }
    Node *binaryTreeToBST(Node *root) {
        // code here
        if (root==NULL)
        return root;
        vector<int>arr;
        findArr(root,arr);
        sort(arr.begin(),arr.end());
        int i=0;
        tobst(root,arr,i);
        return root;
    }
};