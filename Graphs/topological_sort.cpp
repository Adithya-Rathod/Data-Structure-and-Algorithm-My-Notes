#include <bits/stdc++.h>
using namespace std;
// just use dfs code :>

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
    topo_stack.push(node); // pushing to stack while backtracking
}

void display(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
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

    vector<int> topological_sort;
    while (!topo_stack.empty())
    {
        topological_sort.push_back(topo_stack.top());
        topo_stack.pop();
    }

    display(topological_sort);
    return 0;
}

// 6 6
// 2 3
// 3 1
// 4 0
// 4 1
// 5 0
// 5 2