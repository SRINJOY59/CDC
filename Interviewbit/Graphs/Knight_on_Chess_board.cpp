#include<bits/stdc++.h>
using namespace std;

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<int>> dist(A + 1, vector<int>(B + 1, 1e9));
    vector<vector<int>> visited(A + 1, vector<int>(B + 1, 0));

    queue<pair<int, pair<int, int>>> q;
    dist[C][D] = 0;
    visited[C][D] = 1;
    q.push({0, {C, D}});

    while (!q.empty()) {
        int steps = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && ny >= 1 && nx <= A && ny <= B && !visited[nx][ny]) {
                dist[nx][ny] = steps + 1;
                visited[nx][ny] = 1;
                q.push({steps + 1, {nx, ny}});
            }
        }
    }

    return (dist[E][F] == 1e9) ? -1 : dist[E][F];
}
