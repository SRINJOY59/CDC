#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll n;
vector<vector<ll>> adj;
vector<vector<ll>> dp; // dp[u][0] = white, dp[u][1] = black

ll dfs(ll u, ll parent, ll color) {
    if (dp[u][color] != -1) return dp[u][color];

    ll res = 1;

    for (ll v : adj[u]) {
        if (v == parent) continue;

        if (color == 0) {
            // If current is white, child can be black or white
            res *= (dfs(v, u, 0) + dfs(v, u, 1)) % MOD;
        } else {
            // If current is black, child must be white
            res *= dfs(v, u, 0) % MOD;
        }
        res %= MOD;
    }

    return dp[u][color] = res;
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    dp.assign(n + 1, vector<ll>(2, -1));

    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = (dfs(1, 0, 0) + dfs(1, 0, 1)) % MOD;
    cout << ans << endl;

    return 0;
}
