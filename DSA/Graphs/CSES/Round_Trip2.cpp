#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<vector<ll>>&adj, vector<ll>&colors, vector<ll>&parent, ll &cycle_node){
    if(cycle_node != -1) return;
    colors[node] = 2;
    for(auto v : adj[node]){
        if(cycle_node != -1) return;
        if(colors[v] == 1){
            parent[v] = node;
            dfs(v, adj, colors, parent, cycle_node);
        }
        else if(colors[v] == 2){
            cycle_node = v;
            parent[v] = node;
            return;
        }
    }
    colors[node] = 3;
}


int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<ll>colors(n+1, 1);
    vector<ll>parent(n+1, -1);
    ll cycle_node = -1;
    for(ll i = 1;i<=n;i++){
        if(colors[i] == 1)
            dfs(i, adj, colors, parent, cycle_node);
        if(cycle_node!= -1)
            break;
    }
        if(cycle_node != -1){
            vector<ll>path;
            path.push_back(cycle_node);
            ll startnode = parent[cycle_node];
            while(startnode != cycle_node){
                path.push_back(startnode);
                startnode = parent[startnode];
            }
            path.push_back(cycle_node);
            reverse(path.begin(), path.end());
            cout<<path.size()<<endl;
            for(ll i = 0;i<path.size();i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    return 0;
}