#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>>adj(200010);
vector<ll>SubtreeSz(200010, 0);
vector<ll>visited(200010, 0);
void dfs(ll node){
    visited[node] = 1;
    SubtreeSz[node] = 1;
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v);
            SubtreeSz[node] += SubtreeSz[v];
        }
    }
}

int main(){
    ll n;
    cin>>n;
    for(ll i = 2;i<=n;i++){
        ll v;
        cin>>v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    dfs(1);
    for(ll i = 1;i<=n;i++){
        cout<<SubtreeSz[i]-1<<" ";
    }
    cout<<endl;
}