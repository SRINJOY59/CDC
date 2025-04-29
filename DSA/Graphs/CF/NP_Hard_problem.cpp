#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(ll node, vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &white, vector<ll> &black) {
    if (color[node] == 0) white.push_back(node);
    else black.push_back(node);

    for (auto v : adj[node]) {
        if (color[v] == -1) {
            color[v] = 1 - color[node];
            if (!dfs(v, adj, color, white, black)) return false;
        } else if (color[v] == color[node]) {
            return false; 
        }
    }
    return true;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> color(n + 1, -1); 
    vector<ll> white, black;
    bool flag = true;

    for (ll i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!dfs(i, adj, color, white, black)) {
                flag = false;
                break;
            }
        }
    }
    if (!flag) {
        cout << "-1\n";
    } else {
        cout << white.size() << "\n";
        for (auto x : white) cout << x << " ";
        cout << "\n";
        cout << black.size() << "\n";
        for (auto x : black) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
