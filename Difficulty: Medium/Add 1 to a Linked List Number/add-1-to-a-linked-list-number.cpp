/* Structure of linked list Node
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
   int add(Node* head)
   {
       if (head==NULL)
       return 1;
       int  carry=add(head->next);
       int summ=head->data+carry;
       head->data=summ%10;
       carry=summ/10;
       return carry;
       
   }
    Node* addOne(Node* head) 
    {
        // code here
        int carry=add(head);
        if (carry)
        {
            Node* n=new Node(1);
            n->next=head;
            return n;
        }
        return head;
    }
};