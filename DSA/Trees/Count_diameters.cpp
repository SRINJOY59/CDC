#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> parent, depth;
vector<vector<ll>> g;

void dfs(ll node, ll par, ll dep) {
    depth[node] = dep;
    parent[node] = par;
    for (auto v : g[node]) {
        if (v != par) {
            dfs(v, node, dep + 1);
        }
    }
}

ll count_at_depth(ll node, ll par, ll target_depth, ll current_depth) {
    if (current_depth == target_depth) return 1;
    ll cnt = 0;
    for (auto v : g[node]) {
        if (v != par) {
            cnt += count_at_depth(v, node, target_depth, current_depth + 1);
        }
    }
    return cnt;
}

int main() {
    ll n;
    cin >> n;
    parent.resize(n + 1);
    depth.resize(n + 1, 0);
    g.resize(n + 1);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1, 0);
    ll maxch = 1;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > depth[maxch]) {
            maxch = i;
        }
    }

    fill(depth.begin(), depth.end(), 0);
    dfs(maxch, -1, 0);
    ll endpoint = maxch;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > depth[endpoint]) {
            endpoint = i;
        }
    }

    ll diameter = depth[endpoint];
    ll center = endpoint;

    for (ll i = 0; i < diameter / 2; i++) {
        center = parent[center];
    }

    if (diameter % 2 == 0) {  // Single center
        ll count = count_at_depth(center, -1, diameter / 2, 0);
        cout << (count * (count - 1)) / 2 << endl;  // Choosing 2 nodes at depth d/2
    } else {  
        ll center1 = center;
        ll center2 = parent[center];

        ll count1 = count_at_depth(center1, center2, diameter / 2, 0);
        ll count2 = count_at_depth(center2, center1, diameter / 2, 0);

        cout << count1 * count2 << endl;  // Choosing 1 node from each center's subtree
    }

    return 0;
}
