#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll>indegree(n+1, 0);
    vector<vector<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<ll>topo;
    vector<ll>num_paths(n+1, 0);
    queue<ll>q;

    for(ll i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto v : adj[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
    num_paths[1] = 1;
    for(auto x : topo){
        for(auto v : adj[x]){
            num_paths[v] = (num_paths[v] + num_paths[x])%MOD;
        }
    }
    cout<<num_paths[n]<<endl;
    return 0;
}