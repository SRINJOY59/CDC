#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void dfs(ll node, vector<vector<ll>>&adj, vector<ll>&visited, vector<ll>&components){
    visited[node] = 1;
    components.push_back(node);
    for(auto v: adj[node]){
        if(!visited[v]){
            dfs(v, adj, visited, components);
        }
    }
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll sz, u;
        cin>>sz;
        if(sz > 0){
            cin>>u;
        }
        for(ll j = 2;j<=sz;j++){
            ll v;
            cin>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<ll>answer(n+1, 0);
    vector<ll>visited(n+1, 0);
    vector<vector<ll>>components;
    for(ll i = 1;i<=n;i++){
        vector<ll>component;
        if(!visited[i]){
            dfs(i, adj, visited, component);
        }
        components.push_back(component);
    }
    for(ll i = 0;i<components.size();i++){
        for(ll j = 0;j<components[i].size();j++){
            answer[components[i][j]] = components[i].size();
        }
    }
    for(ll i = 1;i<=n;i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}