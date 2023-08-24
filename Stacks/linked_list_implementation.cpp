#include <iostream>
using namespace std;
class node
{

public:
    int val;
    node *next;
    node()
    {
        val = 0;
        next=NULL;        
    }
    node(int data)
    {
        val = data;
        next = NULL;
    }
};

class stack
{

public:
    node *top;
    int capacity;
    stack()
    {  
        top = NULL;
        capacity = 0;
    }
    void push(int x)
    {
        node *cur = new node(x);
        cur->next = top;
        top = cur;
        capacity++;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "NO elements to pop" << endl;
            return;
        }
        node *cur = top;
        top = top->next;
        delete (cur);
        capacity--;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
            return top->val;
    }
    int size()
    {
        return capacity;
    }
};
int main()
{
    stack st;
    st.push(4);
    st.push(2);
    st.push(5);
    st.push(1);
    st.push(87);
    st.push(0);

    st.pop();
    cout << st.size() << endl;
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
 

    cout << (st.isEmpty() ? "EMPTY" : "NON-EMPTY");


    return 0;
}