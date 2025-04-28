#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>topo;

void dfs(ll node, vector<vector<ll>>&adj, vector<ll>&visited){
    visited[node] = 1;
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
    topo.push_back(node);
}

bool isCycle(ll node, vector<vector<ll>>&adj, vector<ll>&visited, vector<ll>&pathvis){
    visited[node] = 1;
    pathvis[node] = 1;
    for(auto v : adj[node]){
        if(!visited[v]){
            if(isCycle(v, adj, visited, pathvis)){
                return true;
            }
        }
        if(pathvis[v]){
            return true;
        }
    }
    pathvis[node] = 0;
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
    }
    vector<ll>visited(n, 0);
    vector<ll>pathvis(n, 0);
    for(ll i = 1;i<=n;i++){
        if(!visited[i-1]){
            if(isCycle(i-1, adj, visited, pathvis)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    visited.assign(n, 0);
    for(ll i = 0;i<n;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
    reverse(topo.begin(), topo.end());
    for(ll i = 0;i<topo.size();i++){
        cout<<topo[i] + 1<<" ";
    }
    cout<<endl;
    return 0;
}