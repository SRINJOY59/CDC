#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(vector<vector<ll>>&adj, ll node, vector<ll>&visited, ll &count, ll N){
    visited[node] = 1;
    count += 1;
    if(count == N){
        return true;
    }
    for(auto v : adj[node]){
        if(!visited[v] && dfs(adj, v, visited, count, N)){
            return true;
        }
    }
    visited[node] = 0;
    count--;
    return false;
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(ll i = 0;i<n;i++){
        ll count = 0;
        vector<ll>visited(n, 0);
        if(dfs(adj, i, visited, count, n)){
            cout<<"Hamiltonian Path found"<<endl;
            return 0;
        }
    }
    cout<<"No Hamiltonian Path"<<endl;
    return 0;
}