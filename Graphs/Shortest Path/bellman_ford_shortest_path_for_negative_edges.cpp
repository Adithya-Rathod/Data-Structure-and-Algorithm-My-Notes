#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void bellmanFord(int n, int m, int source, vector<pair<int, int>> adj[])
{
    vector<int> dist(n, INF);
    queue<pair<int, int>> q;

    dist[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        q.push({source, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int weigth = q.front().second;
            q.pop();
                for (auto it : adj[node])
                {
                    if (dist[it.first] >= dist[node] + it.second)
                    {
                        dist[it.first] = dist[node] + it.second;
                        q.push({it.first, dist[it.first]});
                    }
                }
            
        }
    }

    for (auto it : dist)
    {
        cout << it << " ";
    }
}

int main()
{
    int n, m, source;
    cin >> n >> m >> source;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        // only for DAG(Directed Acyclic Graph)
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    bellmanFord(n, m, source, adj);
    return 0;
}

/*
6 8 0
0 1 10
1 3 2
4 3 -1
2 1 1
0 5 8
4 1 -4
5 4 1
3 2 -2
*/