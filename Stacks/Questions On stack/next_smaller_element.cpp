// given array ke elements ka previous smaller element batana hai

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> a = {1,3,4,2};
    vector<int> b(a.size());
    stack<int> st;

    for (int i = a.size()-1; i >=0 ; i--)
    {
        while(!st.empty() && a[st.top()]<=a[i])
            st.pop();
        if(st.empty())
            b[i]=-1;
        else
            b[i]=st.top();
        st.push(i);
    }
    for(auto it: b) cout<<it<<" ";
    return 0;
}