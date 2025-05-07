#include<bits/stdc++.h>
using namespace std;


class Solution {
private: 
    void dfs1(int u, vector<vector<int>>&adj, vector<int>&visited, stack<int>&st){
        visited[u] = 1;
        for(auto v: adj[u]){
            if(!visited[v])
                dfs1(v, adj, visited, st);
        }
        st.push(u);
    }

    void dfs2(int u, vector<vector<int>>&adj, vector<int>&visited){
        visited[u] = 1;
        for(auto v: adj[u]){
            if(!visited[v]){
                dfs2(v, adj, visited);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        stack<int>st;
        vector<int>visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }

        vector<vector<int>> adjT(n);
        for(int i = 0; i < n; i++) {
            for(auto v: adj[i]) {
                adjT[v].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), 0);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                scc++;
                dfs2(node, adjT, visited);
            }
        }

        return scc;
    }
};


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    Solution sol;
    cout<<sol.kosaraju(adj)<<endl;
    return 0;
}