#include <bits/stdc++.h>
using namespace std;

int n, k;
long long results = 0;
vector<vector<int>> adj(200010);
vector<int> SubtreeSz(200010);
vector<bool> visited(200010);
vector<int> centroids;

int compute_size(int node, int parent) {
    SubtreeSz[node] = 1;
    for (int v : adj[node]) {
        if (v != parent && !visited[v]) {
            SubtreeSz[node] += compute_size(v, node);
        }
    }
    return SubtreeSz[node];
}

void dfs(int node, int parent, int total_size) {
    SubtreeSz[node] = 1;
    bool is_centroid = true;
    for (auto v : adj[node]) {
        if (v != parent && !visited[v]) {
            dfs(v, node, total_size);
            SubtreeSz[node] += SubtreeSz[v];
            if (SubtreeSz[v] > total_size / 2)
                is_centroid = false;
        }
    }
    if (total_size - SubtreeSz[node] > total_size / 2)
        is_centroid = false;
    if (is_centroid && centroids.empty()) {
        centroids.push_back(node);
    }
}

void dfs_depth(int node, int parent, int depth, vector<int>& depths) {
    if (depth > k) return;
    depths.push_back(depth);
    for (auto v : adj[node]) {
        if (v != parent && !visited[v]) {
            dfs_depth(v, node, depth + 1, depths);
        }
    }
}

void decompose(int node) {
    int total_size = compute_size(node, -1);
    centroids.clear();
    dfs(node, -1, total_size);
    int centroid = centroids[0];
    visited[centroid] = true;

    vector<int> counter(k + 1, 0);
    counter[0] = 1;  

    for (auto v : adj[centroid]) {
        if (!visited[v]) {
            vector<int> depths;
            dfs_depth(v, centroid, 1, depths);

            // Count valid pairs directly
            for (int d : depths) {
                if (k - d >= 0) {
                    results += counter[k - d];
                }
            }

            // Add current depths to counter
            for (int d : depths) {
                if (d <= k) counter[d]++;
            }
        }
    }

    for (auto v : adj[centroid]) {
        if (!visited[v]) {
            decompose(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decompose(1);
    cout << results << '\n';

    return 0;
}
