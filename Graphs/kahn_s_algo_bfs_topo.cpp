#include<bits/stdc++.h>
using namespace std;

void toposort(vector<int> adj[], vector<int> &res, vector<int> &indegree )
{
    queue<int> q;
    for(int  i =0 ;i<indegree.size(); i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
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

    vector<int> adj[n];
    vector<int> indegree(n,0);
    for (int i = 0; i < m; i++)
    {
        // only for DAG(Directed Acyclic Graph)
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> res;

    toposort(adj, res, indegree);

    display(res);
    return 0;
}

// 6 6
// 2 3
// 3 1
// 4 0
// 4 1
// 5 0
// 5 2