#include <bits/stdc++.h>
using namespace std;

struct node
{
    int wt;
    int u;
    int v;
    node(int first, int second, int weight) // constructor
    {
        u = first;
        v = second;
        wt = weight;
    }
};

// comperator to tell to store according to weight
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
        parent[v] = u, rank[u]++;
}

int main()
{
    int N, m;
    cin >> N >> m;

    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    // implementing disjoint set data structure
    vector<int> parent(N+1); // parent array
    for (int i = 0; i < N+1; i++)
    {
        parent[i] = i;
    }

    vector<int> rank(N+1, 0); // rank array

    int cost = 0; // cost of mst

    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent)) // if they dont have same parent then push into mst
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            Union(it.u, it.v, parent, rank); // taking union of different components is importent
        }
    }
    cout << "cost of mst: " << cost;
    for (auto it : mst)
    {
        cout << it.first << "-" << it.second << endl;
    }
    return 0;
}

/*
6 9 
1 4 1
1 2 2
2 3 3
2 4 3
1 5 4
3 4 5
2 6 7
8 3 6
9 4 5
*/