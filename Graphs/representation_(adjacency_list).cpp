#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    //vector<pair<int,int>> adj[n+1];   ---> weighted graph 
    for(int i = 0; i<m; i++){
        int u, v;
        //int w   ----> weight
        cin>>u>>v;
        //cin>>w;
        adj[u].push_back(v);
        // adj[u].push_back({v,w});   ----> pushing in with the weights
        adj[v].push_back(u); //for undirected
    }
    return 0;
}
