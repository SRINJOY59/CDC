#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    // dist[node][0] = min distance to node without using coupon
    // dist[node][1] = min distance to node with using coupon
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.emplace(0, 1, 0); // cost, node, used_coupon

    while (!pq.empty()) {
        auto [cost_u, u, used_coupon] = pq.top();
        pq.pop();

        if (cost_u > dist[u][used_coupon]) continue;

        for (auto &[v, w] : adj[u]) {
            // Case 1: Don't use coupon
            if (dist[v][used_coupon] > dist[u][used_coupon] + w) {
                dist[v][used_coupon] = dist[u][used_coupon] + w;
                pq.emplace(dist[v][used_coupon], v, used_coupon);
            }

            // Case 2: Use coupon if not used already
            if (!used_coupon) {
                ll half = w / 2;
                if (dist[v][1] > dist[u][0] + half) {
                    dist[v][1] = dist[u][0] + half;
                    pq.emplace(dist[v][1], v, 1);
                }
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}
