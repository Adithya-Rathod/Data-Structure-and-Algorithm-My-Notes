//SHUNTING YARD ALGORITHM

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '-' || c == '+')
        return 1;
    else
        return 0;
}
void infixToPostfix(string s)
{
    string res;
    stack<char> st;
    for (auto it : s)
    {
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')|| (it >= '0' && it <= '9'))
        {
            res += it;
        }
        else if (it == '(')
        {
            st.push(it);
        }
        else if (it == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty()  && prec(st.top()) >= prec(it))
            {
                res += st.top();
                st.pop();
            }
            st.push(it);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res;
}
int main()
{
    string s;
    cin >> s;
    infixToPostfix(s);
    return 0;
}