#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    vector<vector<ll>> rev_adj(n + 1); // for reverse DFS

    for (ll i = 0; i < m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        edges.emplace_back(a, b, x);
        rev_adj[b].push_back(a); // reverse graph for reachability
    }

    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford
    for (ll i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != -INF && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<bool> affected(n + 1, false);
    for (auto [u, v, w] : edges) {
        if (dist[u] != -INF && dist[v] < dist[u] + w) {
            affected[v] = true;
        }
    }

    vector<bool> visited(n + 1, false);
    function<void(ll)> dfs = [&](ll u) {
        visited[u] = true;
        for (ll v : rev_adj[u]) {
            if (!visited[v])
                dfs(v);
        }
    };
    dfs(n); 

    for (ll i = 1; i <= n; i++) {
        if (affected[i] && visited[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << dist[n] << endl;
    return 0;
}
