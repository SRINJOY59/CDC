#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    const ll INF = 1e18;
    vector<ll> dist(n + 1, INF), parent(n + 1, -1);
    dist[1] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (cost > dist[node]) continue; 
        for (auto [v, wt] : adj[node]) {
            if (dist[v] > dist[node] + wt) {
                dist[v] = dist[node] + wt;
                parent[v] = node;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> path;
    ll terminal = n;
    while (terminal != -1) {
        path.push_back(terminal);
        terminal = parent[terminal];
    }

    reverse(path.begin(), path.end());
    for (ll v : path) cout << v << " ";
    cout << endl;

    return 0;
}
