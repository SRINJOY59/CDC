int cnt = 0;
int mother;
void dfs(int node, vector<vector<int>>&adj, vector<int>&visited){
    visited[node] = 1;
    cnt++;
    for(auto v: adj[node]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
    mother = node;
}

int Solution::motherVertex(int n, vector<vector<int> > &B) {
    vector<vector<int>>adj(n+1);
        for(int i = 0;i<B.size();i++){
            int u = B[i][0];
            int v = B[i][1];
            adj[u].push_back(v);
        }
        vector<int>visited(n+1, 0);
        for(int i = 1;i<=n;i++){
            if(!visited[i]){
                dfs(i, adj, visited);
            }
        }
        cnt = 0;
        for(int i = 1;i<=n;i++){
            visited[i] = 0;
        }
        dfs(mother, adj, visited);
        if(cnt == n)
            return 1;
        else
            return 0;
}
