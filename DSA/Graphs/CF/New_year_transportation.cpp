#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, t;
    cin>>n>>t;
    vector<ll>a(n, 0);
    for(ll i = 1;i<n;i++){
        cin>>a[i];
    }
    vector<vector<ll>>adj(n);
    for(ll i = 1;i<n;i++){
        ll u = i;
        ll v = i + a[i];
        if(v < n){
            adj[u].push_back(v);
        }
    }
    queue<ll>q;
    ll start = 1;
    vector<ll>dist(n, LLONG_MAX);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto v : adj[node]){
            if(dist[v] > dist[node] + 1){
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
    if(dist[t] == LLONG_MAX){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}