#include <bits/stdc++.h>
using namespace std;

void maximumSum(vector<int> &a, int n, int w, vector<int> &b)
{
    deque<int> dq;
    for (int i = 0; i < w; i++)
    {
        if (!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    for (int i = w; i < n; i++)
    {
        b[i - w] = a[dq.front()];
        while (!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();

        while (!dq.empty() && dq.front() <= i - w)
            dq.pop_front();

        dq.push_back(i);
    }
    b[n - w] = a[dq.front()];
}

int main()
{
    vector<int> a={1,3,-1,-3,5,3,6,7};
    int windowSize =3;
    int n = a.size();
    vector<int> b(n - windowSize + 1);
    maximumSum(a, n, windowSize, b);
    for(auto it : b)
        cout<<it<<" ";
    return 0;
}