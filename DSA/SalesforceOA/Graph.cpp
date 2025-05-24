#include <bits/stdc++.h>
using namespace std;
 
pair<int, vector<int>> bfs(int start, const vector<vector<int>> &tree, int n) {
    vector<int> dist(n+1, -1), par(n+1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    int far = start;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nb : tree[cur]){
            if(dist[nb] == -1){
                dist[nb] = dist[cur] + 1;
                par[nb] = cur;
                q.push(nb);
                if(dist[nb] > dist[far])
                    far = nb;
            }
        }
    }
    return {far, par};
}
 
int dfs(int u, int par, const vector<vector<int>> &tree) {
    int best = 0;
    for(auto nb : tree[u]){
        if(nb == par)
            continue;
        best = max(best, 1 + dfs(nb, u, tree));
    }
    return best;
}
 
int optimiseHierarchy(int n, int k, const vector<pair<int,int>> &edges){
    if(n <= 1)
        return 0;
    vector<vector<int>> tree(n+1);
    for(auto &e : edges){
        int u = e.first, v = e.second;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    auto res1 = bfs(1, tree, n);
    int u = res1.first;
    auto res2 = bfs(u, tree, n);
    int v = res2.first;
    vector<int> parent = res2.second;
    vector<int> P;
    for(int cur = v; cur != -1; cur = parent[cur])
        P.push_back(cur);
    reverse(P.begin(), P.end());
    int d = P.size() - 1;
    unordered_map<int,int> posInP;
    for(int i = 0; i < P.size(); i++){
        posInP[P[i]] = i;
    }
    vector<int> L(P.size(), 0);
    for(int i = 0; i < P.size(); i++){
        int node = P[i], best = 0;
        for(auto nb : tree[node]){
            if(posInP.count(nb) && abs(posInP[nb]-i) == 1)
                continue;
            best = max(best, 1 + dfs(nb, node, tree));
        }
        L[i] = best;
    }
    vector<int> L_left = L;
    vector<int> L_right(P.size(), 0);
    for(int i = 0; i < P.size(); i++){
        L_right[i] = L[P.size()-1-i];
    }
    int T = min(k, d), bestCandidate = INT_MAX;
    for(int t = 0; t <= T; t++){
        for(int x = 0; x <= t; x++){
            int y = t - x;
            if(x < L_left.size() && y < L_right.size()){
                int candidate = (d - t) + L_left[x] + L_right[y];
                bestCandidate = min(bestCandidate, candidate);
            }
        }
    }
    int remaining = n - k;
    int ans = (remaining <= 1) ? 0 : max(bestCandidate, 1);
    return ans;
}
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> edges;
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << optimiseHierarchy(n, k, edges)<<endl;
    return 0;
}