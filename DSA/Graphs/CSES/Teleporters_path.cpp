#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void dfs(ll u, vector<multiset<ll>>&adj, vector<ll>&path){
    while(!adj[u].empty()){
        ll v = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        dfs(v, adj, path);
    }
    path.push_back(u);
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<multiset<ll>> adj(n+1);
    vector<ll>Outdegree(n+1, 0);
    vector<ll>Indegree(n+1, 0);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].insert(v);
        Indegree[v]++;
        Outdegree[u]++;
    }

    bool flag = true;
    for(ll i = 1;i<=n;i++){
        //start node outdeg = indeg + 1
        if(i == 1){
            if(Outdegree[i] != Indegree[i] + 1) flag = false;
        }
        else if(i == n){
            if(Indegree[i] != Outdegree[i] + 1) flag = false;
        }
        else{
            if(Indegree[i] != Outdegree[i]) flag = false;
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    
    vector<ll>path;

    dfs(1, adj, path);
    reverse(path.begin(), path.end());
    if(path.size() != m+1 || path.front() != 1 || path.back() != n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto node:path){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}