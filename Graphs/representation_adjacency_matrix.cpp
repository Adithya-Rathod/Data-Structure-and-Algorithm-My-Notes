#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src;
    int des;
    Edge(int source, int destination) : src(source), des(destination) {}
};

class Graph
{
private:
    int V; // number of vertices
    vector<vector<int>> adjMatrix;

public:
    Graph(int numVertices) : V(numVertices)
    {
        // initially all the edges are 0 in the adj matrix
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void insertEdge(const Edge &e)
    {
        int src = e.src;
        int des = e.des;
        if (src >= V || des >= V) // we need to resize
        {
            int newSize = max(src, des) + 1;
            adjMatrix.resize(newSize, vector<int>(newSize, 0));
            V = newSize;
        }

        // if undirected
        adjMatrix[src][des] = 1;
        adjMatrix[des][src] = 1;
    }

    void removeEdge(const Edge &e)
    {
        int src = e.src;
        int des = e.des;
        if (0 <= src < V && 0 <= des < V)
        {
            adjMatrix[src][des] = 0;
            adjMatrix[des][src] = 0;
        }
    }

    bool hasEdge(const Edge &e)
    {
        int src = e.src;
        int des = e.des;
        if (0 <= src < V && 0 <= des < V)
        {
            return (adjMatrix[src][des] || adjMatrix[des][src]);
        }
        else
            return false;
    }

    void print()
    {
        for(int i=0; i<V; i++)
        {
            for(int j =0 ;j<V; j++)
                cout<<adjMatrix[i][j] << " ";
            cout<<endl;
        }
    }

    void destroy()
    {
        V = 0;
        adjMatrix.clear();
    }
};

int main()

{
   /* 
    int n, m; // n = nodes;  m =edges
    cin >> n >> m;

    int adj[n + 1][n + 1]; // adjacent matrix

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    */
   Graph g(3);

   Edge e1(0,1);
   Edge e2(0,2);
   Edge e3(1,2);
   Edge e4(2,3);

   g.insertEdge(e1);
   g.insertEdge(e2);
   g.insertEdge(e3);

   g.print();
   cout<<endl;

   g.insertEdge(e4);

   g.print();
    // limitations: space complexity of O(n^2) and initialization also has tc of O(n^2) if its is sparse
    // enumerating the no. of edges takes O(n) time

    return 0;
}
