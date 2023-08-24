#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> a = {4, 10, 5, 8, 7, 3, 1, 9, 6, 0};
    vector<int> res(a.size());
    stack<int> st;
    for(int i= a.size()-1 ; i>=0; i--)
    {
        while(!st.empty() && a[st.top()]<a[i])
            st.pop();
        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(i);
    }
        for(auto it: res) cout<<it<<" ";

return 0;
}