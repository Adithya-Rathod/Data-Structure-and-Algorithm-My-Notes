#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void dijkstraShortestPath(int n, int source, vector<pair<int, int>> adj[])
{   
    // minimum priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // queue as {distance , node}
    vector<int> distTO(n+1, INF);

    distTO[source] = 0; //dsitance to source
    pq.push({0, source}); //(distTO, from)

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto it : adj[prev])
        {
            int next = it.first;
            int next_dist = it.second;
            //if the current distance is greater than the new distance then please update
            if (distTO[next] >= distTO[prev] + next_dist) //distTO[prev] = dist 
            {
                distTO[next] = distTO[prev] + next_dist;
                pq.push({distTO[next], next});
            }
        }
    }

    for (auto it : distTO)
        if(it!=INF) 
            cout << it << " ";
}

int main()
{
    int n, m, source;
    cin >> n >> m >> source;

    vector<pair<int, int>> adj[n + 1]; // lsit with (node, weight)
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    

    dijkstraShortestPath(n, source, adj);
    return 0;
}

// 5 6 1
// 1 2 2
// 1 4 1
// 4 3 3
// 2 3 4
// 2 5 5
// 3 5 1