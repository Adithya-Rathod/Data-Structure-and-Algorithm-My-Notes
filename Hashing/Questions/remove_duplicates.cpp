#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> given(n);
    for (int i = 0; i < n; i++)
        cin >> given[i];
    unordered_map<int, bool> mp;
    int last=0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(given[i]) == mp.end())
        {   
            given[last++] = given[i];
            mp.insert({given[i], 1});
        }
    }
    given.resize(last);

    for(auto it : given)
        cout<<it<<" "<<endl;
    return 0;
}