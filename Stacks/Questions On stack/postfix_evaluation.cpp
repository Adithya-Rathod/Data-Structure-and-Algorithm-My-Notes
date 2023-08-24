#include <bits/stdc++.h>
using namespace std;

int postfixEval(string s)
{
    stack<char> st;

    for (auto it : s)
    {
        if (isdigit(it))
        {
            st.push(it - '0');
        }
        else
        {
            int topElement = st.top();
            st.pop();
            int sectopElement = st.top();
            st.pop();
            switch (it)
            {
            case '+':
                st.push(sectopElement + topElement);
                break;
            case '-':
                st.push(sectopElement - topElement);
                break;
            case '*':
                st.push(topElement * sectopElement);
                break;
            case '/':
                st.push(sectopElement / topElement);
                break;
            }
        }
    }

    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << postfixEval(s);
    return 0;
}