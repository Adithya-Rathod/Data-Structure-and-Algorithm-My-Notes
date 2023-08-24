// LCS in given two strings [x(1..m)] and [Y(1..n)]
// Brute force: Form every subsequence of X and check whether it is a subsequence
// in Y or not. Every n element of Y will check 2^m subsequence of X
// TC:- O(n) x O(2^m)
#include <bits/stdc++.h>
using namespace std;

void dis(vector<string> a)
{
    for (auto it : a)
        cout << it << endl;
}
int main()
{
    string x, y;
    cin >> x >> y;
    int m = x.size();
    int n = y.size();
    vector<string> vec;
    for (int i = 0; i < m; i++)
    {
        string temp = "";
        for (int j = i; j < m; j++)
        {
            temp += x[j];
            vec.push_back(temp);
        }
    }
    dis(vec);
    for (int i = 0; i < n; i++)
    {
   
    }
    return 0;
}