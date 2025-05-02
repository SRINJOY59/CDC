#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>>adj(200010);
ll cnt = 0;
vector<ll>used(200010);

void dfs(ll node = 1, ll parent = 0){
    for(auto v : adj[node]){
        if(v != parent)
            dfs(v, node);
    }
    if(!used[node] && !used[parent] && parent != 0){
        used[node] = 1;
        used[parent] = 1;
        cnt++;
    }
}

int main(){
    ll n;
    cin>>n;
    for(ll i = 0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout<<cnt<<endl;
    return 0;
}