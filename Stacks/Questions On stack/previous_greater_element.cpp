// given array ke elements ka previous smaller element batana hai

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> a = {4, 10, 5, 8, 7, 3, 1, 9, 6, 0};
    vector<int> b(a.size());
    stack<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        while(!st.empty() && a[st.top()]<=a[i])
            st.pop();
        if(st.empty())
            b[i]=a.size()+1;
        else
            b[i]=st.top();
        st.push(i);
    }
    for(auto it: b) cout<<it<<" ";
    return 0;
}