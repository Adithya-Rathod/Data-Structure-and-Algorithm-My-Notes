#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void floydWarshall(int n, int adj[20][20])
{

    int dist[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = adj[i][j];
        }
    }

    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if(dist[x][y] > dist[x][z] +  dist[z][y])
                    dist[x][y] = dist[x][z] +  dist[z][y];
            }
        }
    }

    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }

}

int main()
{
    int n, m;
    cin >> n >> m;
    int adj[n][n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    floydWarshall(n, adj);
    return 0;
}

