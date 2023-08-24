#include <bits/stdc++.h>
using namespace std;
int span(vector<int> a, int i)
{
    i++;
    int count = 1;
    while (a[i - 1] <= a[i])
    {
        count++;
        i--;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j <n; j++)
    {
        cout<<span(a, j)<<endl;
    }
    return 0;
}