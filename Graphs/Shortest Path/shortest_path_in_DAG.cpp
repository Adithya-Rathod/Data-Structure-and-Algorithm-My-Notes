#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
void toposort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            toposort(it.first, vis, adj, st);
        }
        st.push(node);
    }
}

void shortestPath(int n, int source, vector<pair<int, int>> adj[])
{

    stack<int> st;
    vector<int> vis(n, 0);
    vector<int> dist(n, INF);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            toposort(i, vis, adj, st);
        }
    }
    
    dist[source] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        
            for (auto it : adj[node])
            {
                if (dist[it.first] > dist[node] + it.second)
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        
    }
    for(auto it: dist)
        cout<<it<<" ";
}
int main()
{
    int n, m, source;
    cin >> n >> m >> source;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        // only for DAG(Directed Acyclic Graph)
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    shortestPath(n, source, adj);
    return 0;
}

/*
6 7 0
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
*/