#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll>Indegree(n+1, 0);
    vector<vector<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[v].push_back(u);
        Indegree[u]++;
    }
    priority_queue<ll>pq;
    for(ll i = 1;i<=n;i++){
        if(Indegree[i] == 0)
            pq.push(i);
    }
    vector<ll>topo(n+1);
    ll idx = n;
    while(!pq.empty()){
        ll node = pq.top();
        pq.pop();
        topo[idx--] = node;
        for(auto v : adj[node]){
            Indegree[v]--;
            if(Indegree[v] == 0)
                pq.push(v);
        }
    }
    for(ll i = 1;i<=n;i++){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
    return 0;
}