#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxN = 2e5+10;
vector<vector<ll>>adj(maxN);

ll get_farthest_node(ll start){
    vector<ll>dist(maxN, -1);
    dist[start] = 0;
    queue<ll>q;
    q.push(start);
    ll farthest = start;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto v: adj[node]){
            if(dist[v] == -1){
                dist[v] = dist[node] + 1;
                q.push(v);
                if(dist[v] > dist[farthest])
                    farthest = v;
            }
        }
    }
    return farthest;
}

void bfs(ll node, vector<ll>&dist){
    queue<ll>q;
    q.push(node);
    dist[node] = 1;
    vector<ll>visited(maxN, 0);
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        visited[node] = 1;
        for(auto v: adj[node]){
            if(!visited[v]){
                dist[v] = dist[node]+1;
                q.push(v);
            }
        }
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
    ll u = get_farthest_node(1);
    vector<ll>dist(n+1, -1);
    bfs(u, dist);
    ll diameter = 0;
    for(ll i = 1;i<=n;i++){
        diameter = max(diameter, dist[i]);
    }
    cout<<diameter-1<<endl;
    return 0;
}