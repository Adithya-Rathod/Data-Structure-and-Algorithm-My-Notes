#include <bits/stdc++.h>
using namespace std;


//using stack to store the indices at every iteration and pop if we incur any iteration where the top holds the i's value ssuch that price < stack.top() mei ke index ka array 
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    vector<int> price(n);
    vector<int> span(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && price[i] > price[st.top()])
            st.pop();

        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }

    for(auto it: span) cout<<it<<" ";
    return 0;
}