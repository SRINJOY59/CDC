#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet {
public:
    vector<ll> rank, parent;
    
    DisjointSet(ll n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    ll findUPar(ll node) {
        if (parent[node] != node) {
            parent[node] = findUPar(parent[node]); // Path Compression
        }
        return parent[node];
    }

    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);


        if (rank[ulp_u] >= rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += rank[ulp_v]; 
        } 
         else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += rank[ulp_u];  
        }
    }
};


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        DisjointSet dsu(n);
        vector<tuple<ll, ll, ll>> edges(n - 1);

        for (ll i = 0; i < n - 1; i++) {
            ll u, v, wt;
            cin >> u >> v >> wt;
            edges[i] = {wt, u, v};
            
        }

        sort(edges.begin(), edges.end());  
        reverse(edges.begin(), edges.end());

        ll ans = 0;
        for (auto [wt, u, v] : edges) {
            ll sizeU = dsu.rank[dsu.findUPar(u)];
            ll sizeV = dsu.rank[dsu.findUPar(v)];

            ans += wt * sizeU * sizeV;
            dsu.unionByRank(u, v);
        }
        cout << ans << endl;
    }
    return 0;
}
