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
                cout<<"Resize array"<<endl;
               grow();
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
        void grow()
        {
            int *old_arr = arr;
            capacity*=2;
            arr =new int[capacity];
            for(int i=0; i<capacity/2;i++)
            {
                arr[i]=old_arr[i];
            }
            delete(old_arr);
        };
        void del()
        {
            delete(arr);
        }
 };

int main()
{
    stack st(5);
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.isEmpty()?"yes":"NO";
return 0;
}