#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>subtreeSz;
vector<vector<int>>g;
int ans = 0;
void dfs(int node, int parent){
    subtreeSz[node] = 1;
    for(auto v: g[node]){
        if(v != parent){
            dfs(v, node);
            subtreeSz[node] += subtreeSz[v];
        }
    }
    ans += subtreeSz[node]*(n - subtreeSz[node]);
}

int main(){
    cin>>n;
    subtreeSz.resize(n+1);
    g.resize(n+1);
    for(int i = 0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);

    cout<<ans<<endl;
    return 0;
}