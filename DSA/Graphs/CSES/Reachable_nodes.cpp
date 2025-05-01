#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 5e4+1;
bitset<maxN> ans[maxN];

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>Indegree(n+1, 0);
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        Indegree[v]++;
    }
    queue<int>q;
    vector<int>topo;
    for(int i = 1;i<=n;i++){
        if(Indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto v : adj[node]){
            Indegree[v]--;
            if(Indegree[v] == 0){
                q.push(v);
            }
        }
    }
    reverse(topo.begin(), topo.end());
    for(int u = 1;u<=n;u++){
        ans[u].reset();
        ans[u][u] = 1;
    }
    for(auto u : topo){
        for(auto v : adj[u]){
            ans[u] |= ans[v];
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i].count()<<" ";
    }
    cout<<endl;
    return 0;
}