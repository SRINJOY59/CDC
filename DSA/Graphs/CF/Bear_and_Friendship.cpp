#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& component) {
    visited[node] = 1;
    component.push_back(node);
    for (auto v : adj[node]) {
        if (!visited[v]) {
            dfs(v, adj, visited, component);
        }
    }
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

    vector<ll> visited(n + 1, 0);
    bool flag = true;

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<ll> component;
            dfs(i, adj, visited, component);

            ll edgeCount = 0;
            for (auto node : component) {
                edgeCount += adj[node].size();
            }
            edgeCount /= 2; 

            ll sz = component.size();
            ll maxEdges = sz * (sz - 1) / 2;
            if (edgeCount != maxEdges) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
