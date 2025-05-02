#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>color(200010);
vector<vector<ll>>adj(200010);
vector<set<ll>>Subtree(200010);
vector<ll>visited(200010);


void dfs(ll node){
    visited[node] = 1;
    Subtree[node].insert(color[node]);
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v);
            Subtree[node].insert(Subtree[v].begin(), Subtree[v].end());
        }
    }
}

int main(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;i++){
        cin>>color[i];
    }
    for(ll i = 0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(ll i = 1;i<=n;i++){
        cout<<Subtree[i].size()<<" ";
    }
    cout<<endl;
}