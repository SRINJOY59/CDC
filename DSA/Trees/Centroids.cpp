#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<vector<ll>>g;
vector<ll>SubtreeSz;
vector<ll>centroids;

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

void dfs(ll node, ll parent){
    SubtreeSz[node] = 1;
    bool is_centroid = true;
    for(auto v : g[node]){
        if(v != parent){
            dfs(v, node);
            SubtreeSz[node] += SubtreeSz[v];
            if(SubtreeSz[v] > n/2){
                is_centroid = false;
            }
        }
    }
    if(n - SubtreeSz[node] > n/2) is_centroid = false;
    if(is_centroid){
        centroids.push_back(node);
    }
}

int main(){
    cin>>n;
    g.resize(n+1);
    SubtreeSz.resize(n+1);
    for(ll i = 0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    ll answer = *min_element(centroids.begin(), centroids.end());
    cout<<answer<<endl;    
    return 0;
}