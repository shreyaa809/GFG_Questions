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
class myStack {

  public:
    
    Node* top;
    int sizee=0;
    myStack() 
    {
        // Initialize your data members
    top=NULL;
    sizee=0;
    
    }

    bool isEmpty() 
    {
        // check if the stack is empty
        return top==NULL;
    }

    void push(int x) 
    {
        // Adds an element x at the top of the stack
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        sizee+=1;
    }

    void pop() {
        // Removes the top element of the stack
        if (top==NULL)
        return;
        int x=top->data;
        Node* temp=top;
        top=top->next;
        delete(temp);
        sizee-=1;
    }

    int peek() {
        
        // Returns the top element of the stack
        // If stack is empty, return -1
        if (sizee==0)
        return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sizee;
    }
};