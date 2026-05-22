/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) 
    {
        // code here
       
        Node* slow=head;
        Node* fast=head;
        int cnt=1;
        while (fast!=NULL&& fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if (slow==fast)
            {
                slow=slow->next;
                while (slow!=fast)
                {
                   cnt++;
                   slow=slow->next;
                }
                return cnt;
            }
        }
        return 0;
    }
};