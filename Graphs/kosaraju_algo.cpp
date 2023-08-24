#include <bits/stdc++.h>
using namespace std;

void toposort(int node, vector<int> adj[], vector<int> &vis, stack<int> &topo_stack)
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            toposort(it, adj, vis, topo_stack);
        }
    }
    topo_stack.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[node])
        {
            revDFS(it, vis, transpose);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        // only for DAG(Directed Acyclic Graph)
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> topo_stack;
    vector<int> vis(n, 0); // starts from index 0

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            toposort(i, adj, vis, topo_stack);
        }
    }

    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while (!topo_stack.empty())
    {
        int node = topo_stack.top();
        topo_stack.pop();
        if (!vis[node])
        {
            cout << "SCC: " << endl;
            revDFS(node, vis, transpose);
            cout << endl;
        }
    }
    return 0;
}