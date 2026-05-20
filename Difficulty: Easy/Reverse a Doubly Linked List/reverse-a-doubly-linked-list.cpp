/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* temp=head;
        int cnt=0;
        if(head==NULL )
        return NULL;
        while (temp->next!=NULL)
        {
        temp=temp->next;
        cnt++;
        }
        
       
        cnt++;
        Node* tempp=head;
        for (int i=1;i<=cnt/2;i++)
        {
            if (tempp!=temp||tempp->prev!=temp->next) //so thwy dont cross 
            {
            int dat=tempp->data;
            tempp->data=temp->data;
            temp->data=dat;
            tempp=tempp->next;
            temp=temp->prev;
            }
            else break;
        }
        return head;
    }
};