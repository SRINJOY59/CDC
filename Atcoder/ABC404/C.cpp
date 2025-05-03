#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;


    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if (m != n) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<bool> visited(n + 1, false);
    dfs(1, adj, visited);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
