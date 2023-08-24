#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ques;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ques.push_back({x, y});
    }
    unordered_map<int, int> hash;
    for (auto it : ques)
    {
        hash.insert(it);
        if (hash.find(it.second) != hash.end())
        {
            if (hash[it.second] = it.first)
            {
                cout  << "("<< it.first  << " "<< it.second << ")";
                cout  << "("<< it.second << " " << it.first  << ")"<<endl;
            }
        }
    }
    return 0;
}