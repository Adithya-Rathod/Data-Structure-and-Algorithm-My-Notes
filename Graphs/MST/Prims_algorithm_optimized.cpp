
// optimised using head datastructure priority queue
// because scrroling in key will

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n]; // lsit with (node, weight)
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> key(n, INF);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0}); // key value i.e. its weight and its index

    for (int count = 0; count < n - 1; count++) // iteration for every element in graph till the n-1 i.e. no. of edges of mst
    {  
         //minimum wala is at the top in a priority queue
        int u = pq.top().first; // o(logV)
        pq.pop();

        /*
                int mini = INF;
                int mini_ind;

                for (int i = 0; i < n; i++) // scrolling in the key array to find the key which will be of weight minimum and not a part of our mst
                {
                    if (mstSet[i] == false && mini > key[i])
                    {
                        mini = key[i];
                        mini_ind = i;
                    }
                }
                //this loop makes tc n^2

        */

        mstSet[u] = true; // now drawing the mini key node

        for (auto it : adj[u]) // adjacent nodes of the minimum key node
        {
            int node = it.first;
            int weight = it.second;

            if (mstSet[node] == false && weight < key[node]) // if the the elements in the adj list of the key element is in the mstset or not && if the weight that element is less than than that in the key weight
            {
                parent[node] = u; // parent becomes the minimum key
                key[node] = weight; // storing the updated key weight
                pq.push({key[node], node});
            }
        }
    }

    for (int i = 1; i < n; i++) // the parent element and indexes refer to the edges of the graph which are involved in the mst
        cout << parent[i] << "-" << i << endl;
    // iterated from 1 bc 0 is not a starting node it itself is the parent to itseld XD

    return 0;
}

/*
5 6
0 3 6
0 1 2
3 1 8
1 2 3
1 4 5
4 2 7
*/