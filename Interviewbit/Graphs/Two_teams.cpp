#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int c) {
    color[node] = c;
    for (auto v : adj[node]) {
        if (color[v] == -1) {
            if (!dfs(v, adj, color, 1 - c)) {
                return false;
            }
        }
        else if (color[v] == color[node]) {
            return false;
        }
    }
    return true;
}

int Solution::solve(int A, vector<vector<int>> &B) {
    vector<vector<int>> adj(A + 1);
    for (auto &edge : B) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(A + 1, -1);
    
    for (int i = 1; i <= A; i++) {
        if (color[i] == -1) {
            if (!dfs(i, adj, color, 0)) {
                return false;
            }
        }
    }
    return true;
}
