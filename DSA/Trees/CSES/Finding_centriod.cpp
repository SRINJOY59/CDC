#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>adj(200010);
vector<int>SubtreeSz(200010, 0);
vector<int>centroids;

void dfs(int node, int parent){
    SubtreeSz[node] = 1;
    bool is_centriod = true;
    for(auto v: adj[node]){
        if(v != parent){
            dfs(v, node);
            SubtreeSz[node] += SubtreeSz[v];
            if(SubtreeSz[v] > n/2){
                is_centriod = false;
            }
        }
    }
    if(n - SubtreeSz[node] > n/2) is_centriod = false;
    if(is_centriod)
        centroids.push_back(node);
}


int main(){
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout<<centroids[0]<<endl;
    return 0;
}