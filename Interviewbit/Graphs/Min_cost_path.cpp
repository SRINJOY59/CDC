#include<bits/stdc++.h>
using namespace std;

int Solution::solve(int A, int B, vector<string> &C) {
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, -1, 0, 1};
    map<char, int>mp;
    mp['U'] = 0;    
    mp['L'] = 1;
    mp['D'] = 2;
    mp['R'] = 3;
    vector<vector<int>>dist(A, vector<int>(B, 1e9));
    dist[0][0] = 0;
    deque<pair<int, int>>q;
    q.push_front({0, 0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >=0 && nx < A && ny < B){
                int cost = 1;
                if(mp[C[x][y]] == i) cost = 0;
                if(dist[nx][ny] > dist[x][y] + cost){
                    dist[nx][ny] = dist[x][y] + cost;
                    if(cost == 0) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
    }
    return dist[A-1][B-1];
}
