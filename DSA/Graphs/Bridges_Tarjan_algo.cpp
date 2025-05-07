#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&tin, vector<int>&low, vector<int>&visited, vector<vector<int>>&bridges){
        visited[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto v: adj[node]){
            if(v == parent) continue;
            if(!visited[v]){
                dfs(v, node, adj, tin, low, visited, bridges);
                low[node] = min(low[node], low[v]);
                if(low[v] > tin[node]){
                    bridges.push_back({v, node});
                }
            }
            else{
                low[node] = min(low[node], low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i = 0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>bridges;
        vector<int>tin(n, 0);
        vector<int>low(n, 0);
        vector<int>visited(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, -1, adj, tin, low, visited, bridges);
            }
        }
        return bridges;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>edges(m);
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
    }
    Solution sol;
    vector<vector<int>>bridges = sol.criticalConnections(n, edges);
    for(int i = 0;i<bridges.size();i++){
        cout<<bridges[i][0]<<" "<<bridges[i][1]<<endl;
    }
    return 0;
}