#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 1;

    void dfs(int u, int parent, vector<int> adj[], vector<int>& visited,
             vector<int>& tin, vector<int>& low, set<int>& points) {
        visited[u] = 1;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u, adj, visited, tin, low, points);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && parent != -1)
                    points.insert(u);
                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1)
            points.insert(u);
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), tin(V, 0), low(V, 0);
        set<int> points;

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, -1, adj, visited, tin, low, points);
        }

        if (points.empty()) return { -1 };

        return vector<int>(points.begin(), points.end());
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph:
    // 0 --- 1 --- 2
    //       |
    //       3
    //       |
    //       4

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution sol;
    vector<int> result = sol.articulationPoints(V, adj);

    cout << "Articulation Points: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
