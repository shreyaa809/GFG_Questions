/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  Node* findmid(Node* head)
  {
      Node* fast=head;
      Node* slow=head;
      while (fast->next!=NULL&& fast->next->next!=NULL)
      {
          fast=fast->next->next;
          slow=slow->next;
      }
      return slow;
  }
    Node* ms(Node* head)
    {
        if (head==NULL||head->next==NULL)
        return head;
        Node* mid=findmid(head);
        Node* dummy=mid;
        
        Node* left=head;
        Node* right=dummy->next;
        mid->next=NULL;
        
        left=ms(left);
        right=ms(right);
        return merge (left,right);
    }
    Node* merge (Node* left,Node*right)
    {
        if(left==NULL)
        return right;
        if (right==NULL)
        return left;
        Node* newNode=new Node(-1);
        Node* n=newNode;
        while (left!=NULL&& right!=NULL)
        {
            if (left->data>right->data)
            {
                n->next=right;
                right=right->next;
            }
            else{
                n->next=left;
                left=left->next;
                
            }
            n=n->next;
        }
        while (left!=NULL)
        {
            n->next=left;
            left=left->next;
            n=n->next;
        }
        while (right!=NULL)
        {
              n->next=right;
              right=right->next;
              n=n->next;
        }
        return newNode->next;
    }
    Node* segregate(Node* head) 
    {
        // code here
        return ms(head);
    }
};