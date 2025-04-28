#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<vector<ll>>&adj, vector<ll>&visited){
    visited[node] = 1;
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll> indegree(n, 0);

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v; 
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<ll>visited(n, 0);
    dfs(0, adj, visited);

    if(!visited[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    queue<ll> q;
    for (ll i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<ll> dist(n, LLONG_MIN); 
    vector<ll> parent(n, -1);

    dist[0] = 0; 

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }


    vector<ll> path;
    for (ll cur = n-1; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto city : path) {
        cout << city + 1 << ' '; 
    }
    cout << '\n';

    return 0;
}
