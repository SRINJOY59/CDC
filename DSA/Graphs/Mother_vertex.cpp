#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt = 0;
int mother;

template<typename T>
vector<T> sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>adj(n+1);
        for(int i = 0;i<m;i++){
            int u, v;
            cin>>u>>v;
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
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}