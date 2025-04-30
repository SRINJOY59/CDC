#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<ll>Indegree(n+1, 0);
        vector<vector<ll>>adj(n+1);
        for(ll i = 0;i<m;i++){
            ll u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            Indegree[v]++;
        }
        vector<ll>topo;
        queue<ll>q;
        vector<ll>dist(n+1, 1e18);
        ll startnode = 1;
        dist[startnode] = 0;
        vector<ll>num_paths(n+1, 0);
        num_paths[startnode] = 1;
        for(ll i = 1;i<=n;i++){
            if(Indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            ll node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto v : adj[node]){
                Indegree[v]--;
                if(Indegree[v] == 0)
                    q.push(v);
                if(dist[v] == 1e18){
                    dist[v] = dist[node] + 1;
                    num_paths[v] = num_paths[node];
                }
                else{
                    dist[v] = min(dist[v], dist[node] + 1);
                    num_paths[v] = min(2LL, num_paths[v] + num_paths[node]); 
                }
            }
        }
        vector<ll>visited(n+1, 0);
        for(ll i = 0;i<topo.size();i++){
            visited[topo[i]] = 1;
        }
        for(ll i = 1;i<=n;i++){
            if(!visited[i])
                num_paths[i] = -1;
        }
        for(ll i = 1;i<=n;i++){
            cout<<num_paths[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}