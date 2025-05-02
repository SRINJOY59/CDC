#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
const ll maxN = 2e5+10;
vector<vector<ll>>adj(maxN);

void bfs(ll node, vector<ll>&dist){
    queue<ll>q;
    dist[node] = 0;
    q.push(node);
    vector<ll>visited(n+1, 0);
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        visited[node] = 1;
        for(auto v: adj[node]){
            if(!visited[v]){
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
}

ll get_farthest_node(ll node){
    queue<ll>q;
    q.push(node);
    vector<ll>dist(maxN, -1);
    dist[node] = 0;
    ll farthest = node;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto v: adj[node]){
            if(dist[v] == -1){
                dist[v] = dist[node] + 1;
                q.push(v);
                if(dist[v] > dist[farthest]){
                    farthest = v;
                }
            }
        }
    }
    return farthest;
}

int main(){
    cin>>n;
    for(ll i = 0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll u = get_farthest_node(1);
    ll v = get_farthest_node(u);

    vector<ll>dist_u(n+1);
    vector<ll>dist_v(n+1);
    bfs(u, dist_u);
    bfs(v, dist_v);
    for(ll i = 1;i<=n;i++){
        cout<<max(dist_u[i], dist_v[i])<<" ";
    }
    cout<<endl;
    return 0;
}