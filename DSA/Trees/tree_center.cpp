#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> depth, parent;
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

int main() {
    ll n;
    cin >> n;
    depth.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    g.resize(n + 1);

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

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

    ll endpoint = maxch;
    dfs(endpoint, -1, 0);

    maxch = endpoint;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > depth[maxch]) {
            maxch = i;
        }
    }

    ll diameter = depth[maxch];
    ll center = maxch;
    for (ll i = 0; i < diameter / 2; i++) {
        center = parent[center];
    }

    if (diameter % 2 == 0) {
        cout << center << endl;
    } else {
        cout << center << parent[center] << endl;
    }

    return 0;
}
