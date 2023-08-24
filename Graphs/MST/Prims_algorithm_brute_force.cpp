//the tc in the this case goes O(n^2)
//optimised using head datastructure priority queue

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

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) // iteration for every element in graph till the n-1 i.e. no. of edges of mst
    {
        int mini = INF;
        int mini_ind;

        for (int i = 0; i < n; i++) // scrolling in the key array to find the key which will be of weight minimum and not a part of our mst
        {
            if (mstSet[i] == false && mini > key[i])
            {
                mini = key[i];
                mini_ind = i;
            }
        }//this loop makes tc n^2

        mstSet[mini_ind] = true; // now drawing the mini key node

        for (auto it : adj[mini_ind]) // adjacent nodes of the minimum key node
        {
            if (mstSet[it.first] == false && it.second < key[it.first]) // if the the elements in the adj list of the key element is in the mstset or not && if the weight that element is less than than that in the key weight
            {
                key[it.first] = it.second;   // storing the updated key weight
                parent[it.first] = mini_ind; // parent becomes the minimum key
            }
        }
    }

    for (int i = 1; i < n; i++)     //the parent element and indexes refer to the edges of the graph which are involved in the mst
        cout << parent[i] << "-" << i << endl;
        //iterated from 1 bc 0 is not a starting node it itself is the parent to itseld XD

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