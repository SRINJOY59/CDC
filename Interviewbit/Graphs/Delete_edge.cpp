#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void dfs(int node, vector<vector<int>> &adj, vector<int> &weights, vector<int> &visited, vector<int> &Subtree) {
    Subtree[node] = weights[node - 1]; // weights are 0-indexed
    visited[node] = 1;
    for (auto v : adj[node]) {
        if (!visited[v]) {
            dfs(v, adj, weights, visited, Subtree);
            Subtree[node] += Subtree[v];
        }
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B) {
    int n = A.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += A[i];
    }

    vector<int> Subtree(n + 1, 0);
    vector<int> visited(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < B.size(); i++) {
        int u = B[i][0];
        int v = B[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, A, visited, Subtree);

    long long totalSum = Subtree[1]; // total weight of tree

    long long maxProduct = 0;
    for (int i = 2; i <= n; ++i) { // Skip root node (1), can't cut above it
        long long part1 = Subtree[i];
        long long part2 = totalSum - part1;
        maxProduct = max(maxProduct, part1 * part2);
    }
    return maxProduct%MOD;
}
