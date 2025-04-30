#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<multiset<ll>>&adj, vector<ll>&path){
    while(!adj[node].empty()){
        ll v = *adj[node].begin();
        adj[node].erase(adj[node].begin());
        adj[v].erase(adj[v].find(node));
        dfs(v, adj, path);
    }
    path.push_back(node);
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<multiset<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool flag = true;
    for(ll i = 1;i<=n;i++){
        if(adj[i].size() % 2 == 1){
            flag = false;
            break;
        }
    }
    if(flag){
        vector<ll>path;
        dfs(1, adj, path);
        reverse(path.begin(), path.end());
        if(path.size() != m+1 || path.front() != 1 || path.back() != 1){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            for(auto node:path){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}