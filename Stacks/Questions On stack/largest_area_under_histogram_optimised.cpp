#include <bits/stdc++.h>
using namespace std;

// checking the previous smallest using stack and finding the next smallest using stack then for every index just (nexSmalles[i]-prevSmalles[i] -1)*a[i]
// TC :- O(n) + O(n) + O(n)

vector<int> prevSmallest(vector<int> &a, int n)
{
    stack<int> st;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;
}
vector<int> nextSmallest(vector<int> &a, int n)
{
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        if (st.empty())
            res[i] = n + 1;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;
}
void print(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << "\n";
}
int main()
{
    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    int n = a.size();
    int maxArea = 0;
    vector<int> ns = nextSmallest(a, n);
    print(ns);
    vector<int> ps = prevSmallest(a, n);
    print(ns);
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (ns[i] - ps[i] - 1) * a[i]);
    }
    cout << maxArea << endl;
    return 0;
}