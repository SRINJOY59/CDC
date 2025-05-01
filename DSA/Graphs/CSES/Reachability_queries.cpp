#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 5e4+1;
bitset<maxN> reachable[maxN];

int main() {
    int n, m, query_count;
    cin >> n >> m >> query_count;

    vector<int> Indegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Indegree[v]++;
        adj[u].push_back(v);
    }

    queue<int> topo_queue;
    for (int i = 1; i <= n; i++) {
        if (Indegree[i] == 0) {
            topo_queue.push(i);
        }
    }

    vector<int> topo;
    while (!topo_queue.empty()) {
        int node = topo_queue.front();
        topo_queue.pop();
        topo.push_back(node);
        for (auto v : adj[node]) {
            Indegree[v]--;
            if (Indegree[v] == 0)
                topo_queue.push(v);
        }
    }

    for (int u = 1; u <= n; u++) {
        reachable[u].reset();
        reachable[u][u] = 1;
    }

    reverse(topo.begin(), topo.end()); 
    for (auto u : topo) {
        for (auto v : adj[u]) {
            reachable[u] |= reachable[v]; 
        }
    }

    while (query_count--) {
        int u, v;
        cin >> u >> v;
        cout << (reachable[u][v] ? "YES" : "NO") << '\n';
    }

    return 0;
}
