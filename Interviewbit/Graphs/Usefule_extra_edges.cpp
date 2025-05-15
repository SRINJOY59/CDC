#include<bits/stdc++.h>
using namespace std;

vector<int> dijikstra(int src, vector<vector<pair<int, int>>>&adj, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dist(n+1, 1e9);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[v] > dist[node] + wt){
                dist[v] = dist[node] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pair<int, int>>>adj(A+1);
    for(int i = 0;i<B.size();i++){
        int u = B[i][0];
        int v = B[i][1];
        int cost = B[i][2];
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    vector<int>distFromC = dijikstra(C, adj, A);
    vector<int>distFromD = dijikstra(D, adj, A);
    
    int min_dist = distFromC[D];
    for(auto edge: E){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        min_dist = min(min_dist, distFromC[u] + wt + distFromD[v]);
        min_dist = min(min_dist, distFromD[u] + wt + distFromC[v]);
    }
    if(min_dist == 1e9) min_dist = -1;
    return min_dist;
}
