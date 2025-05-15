#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (auto v : adj[node]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A + 1);
    for (int i = 0; i < B.size(); i++) {
        int id = B[i][0];
        int parent_id = B[i][1];
        adj[parent_id].push_back(id);
        adj[id].push_back(parent_id);
    }

    vector<int> visited(A + 1, 0);
    int count = 0;

    for (int i = 1; i <= A; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}
