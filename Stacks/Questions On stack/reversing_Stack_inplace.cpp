#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int &data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(temp);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int data = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,data);
}

int main()
{
    stack<int> st;
    st.push(2);
    st.push(5);
    st.push(3);
    st.push(1);
    st.push(4);
    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}