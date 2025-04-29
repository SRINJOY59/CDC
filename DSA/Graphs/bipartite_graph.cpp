#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>&adj, vector<int>&color){
    for(auto v : adj[node]){
        if(color[v] == -1){
            color[v] = 1 - color[node];
            if(!dfs(v, adj, color)) return false;
        }
        else if(color[v] == color[node]){
            return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<vector<int>> &edges) {
    vector<vector<int>>adj(V+1);
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = true;
    vector<int>color(V+1, -1);
    for(int i = 1;i<=V;i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!dfs(i, adj, color)){
                flag = false;
                break;
            }
        }
    }
    if(!flag){
        return false;
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>edges(m, vector<int>(2, 0));
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
    }
    if(isBipartite(n, edges)){
        cout<<"Bipartite"<<endl;
    }
    else{
        cout<<"Not Bipartite"<<endl;
    }
    return 0;
}