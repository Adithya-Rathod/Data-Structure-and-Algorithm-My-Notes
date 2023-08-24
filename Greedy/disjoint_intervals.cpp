#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<pair<int, int>> q;
    for(int i =0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        q.push({y,x});
    }
    sort(&q.front(), &q.back());
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    int count =0;
    for(int i =1; i<n ; i++)
    {
        if(v[i-1].second < v[i].first)
            count++;
        else
            continue;
    }

    cout<<count;
    return 0;
}