#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &StoreBFS){
    
    queue<int> q;
    q.push(node);
    vis[node] =1;

    while(!q.empty()){
        node = q.front();
        q.pop();
        StoreBFS.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }

}


void display(vector<int> &v){
    for(auto it : v)
        cout<<it<<" ";
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];
    for(int i=0; i<m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    
    vector<int> vis(n+1, 0);
    vector<int> StoreBFS;

    for(int i=1; i<=m; i++){
        if(!vis[i]){
            bfs(i, adj, vis, StoreBFS);
        }
    }

    display(StoreBFS);
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