#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
// for graph starting from 0 to n
// shortest distance of every node from source node

void SDbyBFS(int N, vector<int> adj[], int source)
{
    vector<int> dist(N, INF);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            {
                if (dist[it] > dist[node] + 1)
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout << dist[i] << " "; // shortest distance of every node from soure node
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cin >> source;
    SDbyBFS(n, adj, source);

    return 0;
}

// 9 11
// 0 1
// 0 3
// 1 3
// 1 2
// 3 4
// 4 5
// 5 6
// 2 6
// 6 7
// 7 8
// 6 8
// 0