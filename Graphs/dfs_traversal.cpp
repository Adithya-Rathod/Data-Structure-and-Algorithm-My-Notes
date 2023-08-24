#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &StoreDFS)
{
    StoreDFS.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {   
        if (!vis[it])
        {
            dfs(it, adj, vis, StoreDFS);
        }
    }
}


vector<int> dfsIterative(vector<int> adj[], int n)
{

    vector<int> ans;
    stack<int> st;
    vector<bool> vis(n + 1, 0);
    
    st.push(0);
    while(!st.empty())
    {
        int index = st.top();
        st.pop();
        ans.push_back(index);
        for(auto it : adj[index])
        {
            if(!vis[it])
            {
                st.push(it);
                vis[it] = true;
            }
        }
    }
    return ans;

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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> StoreDFS = dfsIterative(adj, n);
    // vector<int> vis(n + 1, 0);

    // for (int i = 1; i <= n; i++)
    // {
    //     if (!vis[i])
    //     {
    //         dfs(i, adj, vis, StoreDFS);
    //     }
    // }

    display(StoreDFS);

    return 0;
}

// 8 8
// 1 2
// 2 8
// 2 3
// 3 4
// 3 5
// 8 5
// 5 7
// 5 6