#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m;
    cin>>n>>m;
    string str;
    cin>>str;
    vector<ll>Indegree(n+1, 0);
    vector<vector<ll>>adj(n+1);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        Indegree[v]++;
    }
    vector<ll>topo;
    queue<ll>q;
    for(ll i = 1;i<=n;i++){
        if(Indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto v : adj[node]){
            Indegree[v]--;
            if(Indegree[v] == 0)
                q.push(v);
        }
    }
    if(topo.size() != n){
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<ll>>scores(n+1, vector<ll>(26, 0));
    for(auto node : topo){
        scores[node][str[node-1]-'a'] += 1;
        for(auto v : adj[node]){
            for(int i = 0;i<26;i++){
                scores[v][i] = max(scores[v][i], scores[node][i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, *max_element(scores[i].begin(), scores[i].end()));
    }
    cout<<ans<<endl;
    return 0;
}