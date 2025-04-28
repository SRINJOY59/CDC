#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll rec(vector<vector<ll>>&adj, ll node, vector<ll>&dp){
    if(dp[node] != -1){
        return dp[node];
    }
    ll ans = 1;
    for(auto v : adj[node]){
        ans = max(ans, 1 + rec(adj, v, dp));
    }
    return dp[node] = ans;
}
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    for(ll i = 0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    vector<ll>dp(n, -1);
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ans = max(ans, rec(adj, i, dp));
    }
    cout<<ans-1<<endl;
    return 0;
}