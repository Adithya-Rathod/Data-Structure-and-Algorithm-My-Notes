#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    unordered_map<int, int> hash;
    for (auto i : a)
    {
        if (hash.find(i) == hash.end())
            hash.insert({i, 1});
        else
            hash[i]++;
    }
    bool flag = false;
    for (auto j : b)
    {
        if (hash.find(j) == hash.end())
            flag=true;
        else
        {
            if (hash[j] != 0)
                hash[j]--;
            else
                hash.erase(j);
        }
    }
    if(!flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}