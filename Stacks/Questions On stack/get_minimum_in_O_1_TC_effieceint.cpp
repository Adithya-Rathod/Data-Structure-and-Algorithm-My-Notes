/* efficeint in space complexity*/
//efficiency improved by putting a check 
//during push, check if the x is smaller that minstack top if yes then only add... push in element stack no problem
//during pop, check if the top of element stack is the same as the top of minStack element if yes then pop both of them or else just pop element stack and move on

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

class advacedstack{

    public:
    stack element;
    stack minStack;
    bool isEmpty()
    {
        return element.isEmpty();
    }
    int sizeA()
    {
        return element.size();
    }
    void pushA(int x)
    {
        element.push(x);
        if(!minStack.isEmpty())
        {
            if(x < minStack.Top())
                minStack.push(x);
        }
        else 
            minStack.push(x);
    }
    void popA()
    {
        if(element.Top()==minStack.Top())
            minStack.pop();
        element.pop();
        
    }
    int getMinimum()
    {
        if(!minStack.isEmpty())
            return minStack.Top();
        else 
            return -1e3;
    }
};
int main()
{
    advacedstack adv;
    adv.pushA(4);
    adv.pushA(5);
    adv.pushA(7);
    adv.pushA(3);
    adv.pushA(8);
    adv.pushA(2);
    adv.pushA(1);

    cout<<adv.getMinimum()<<endl;
    adv.popA();
    cout<<adv.getMinimum()<<endl;
    return 0;
}