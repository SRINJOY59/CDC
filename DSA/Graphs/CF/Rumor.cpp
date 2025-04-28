#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll>&visited, vector<vector<ll>>&adj, vector<ll>&golds, ll &min_cost){
    visited[node] = 1;
    min_cost = min(min_cost, golds[node]);
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v, visited, adj, golds, min_cost);
        }
    }
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll>golds(n);
    for(ll i = 0;i<n;i++){
        cin>>golds[i];
    }
    vector<vector<ll>>adj(n);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    vector<ll>visited(n, 0);
    for(ll i = 0;i<n;i++){
        if(!visited[i]){
            ll min_cost = LLONG_MAX;
            dfs(i, visited, adj, golds, min_cost);
            ans += min_cost;
        }
    }
    cout<<ans<<endl;
    return 0;
}