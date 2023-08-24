#include<iostream>
using namespace std;
 class stack
 {
    int top;
    int capacity;
    int *arr;
    public:
        stack(int n)
        {
            top =-1;
            capacity =n;
            arr= new int[capacity]; 
        }

        void push(int x)
        {
            if(top==capacity-1){
                cout<<"stack overflow";
                return;
                }
            top++;
            arr[top]=x;
        }

        void pop()
        {
            if(top==-1)
               cout<<"No element to pop"<<endl;
            
            top--;
        }
        int size()
        {
             return top+1;
        }
        bool isEmpty()
        {
            return top==-1;
        }
        int Top()
        {
            if(top==-1){
                cout<<"no element in stack";
                return -1;
                }
            return arr[top];
        }
        
 };

int main()
{
    stack st(5);
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(6);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.isEmpty();
return 0;
}