#include<bits/stdc++.h>
using namespace std;

int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B) {
    int start = 1;
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(101, 1e9);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int n_node = node + i;

            if (n_node > 100) continue; 

            int index = -1;

            for (int j = 0; j < A.size(); j++) {
                if (A[j][0] == n_node) {
                    index = j;
                    break;
                }
            }

            if (index != -1) {
                n_node = A[index][1]; 
            } else {
                for (int j = 0; j < B.size(); j++) {
                    if (B[j][0] == n_node) {
                        index = j;
                        break;
                    }
                }

                if (index != -1) {
                    n_node = B[index][1];
                }
            }

            if (dist[n_node] > dist[node] + 1) {
                dist[n_node] = dist[node] + 1;
                q.push({dist[n_node], n_node});
            }
        }
    }

    return dist[100] == 1e9 ? -1 : dist[100];
}
