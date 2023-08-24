#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int rankarr[10000];

void makeSet(int n){
    for(int i=1; i<=n; i++){
        parent[i]=i;
        rankarr[i]=0;
    }
}

int findPar(int node){
    if(node == parent[node])
        return node;

    return parent[node] = findPar(parent[node]); //path compression tc O(4alpha) i.e. O(constant)
    //return find(parent[node]) ---> w/o path compression tc of O(log n)
}

void Union(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if(rankarr[u]<rankarr[v])
        parent[u]=v;
    else if(rankarr[u]>rankarr[v])
        parent[v]= u;
    else
        parent[v] =u, rankarr[v]++;

}
int main()
{   
    int m;
    cin>>m;
    while(m--){
        int u, v;
        Union(u, v);
    }
    return 0;
}