#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<ll> dist(n + 1, 1e18);
    vector<ll> num_paths(n + 1, 0);
    vector<ll> min_flights(n + 1, 1e9);
    vector<ll> max_flights(n + 1, 0);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    dist[1] = 0;
    num_paths[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dist[node]) continue;

        for (auto [v, cost] : adj[node]) {
            if (dist[v] > dist[node] + cost) {
                dist[v] = dist[node] + cost;
                num_paths[v] = num_paths[node];
                min_flights[v] = min_flights[node] + 1;
                max_flights[v] = max_flights[node] + 1;
                pq.push({dist[v], v});
            } else if (dist[v] == dist[node] + cost) {
                num_paths[v] = (num_paths[v] + num_paths[node]) % MOD;
                min_flights[v] = min(min_flights[v], min_flights[node] + 1);
                max_flights[v] = max(max_flights[v], max_flights[node] + 1);
            }
        }
    }

    if (dist[n] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << " " << num_paths[n] << " " << min_flights[n] << " " << max_flights[n] << endl;
    }

    return 0;
}