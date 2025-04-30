#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll i, ll j, vector<vector<ll>> &dungeon, vector<vector<ll>> &dp, ll n, ll m) {
    if (i >= n || j >= m) return LLONG_MAX; 

    if (dp[i][j] != -1) return dp[i][j]; 

    if (i == n - 1 && j == m - 1) {
        return dp[i][j] = max(1LL, 1 - dungeon[i][j]);
    }

    ll right = dfs(i, j + 1, dungeon, dp, n, m);
    ll down = dfs(i + 1, j, dungeon, dp, n, m);

    ll min_next = min(right, down);
    dp[i][j] = max(1LL, min_next - dungeon[i][j]);
    return dp[i][j];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> dungeon(n, vector<ll>(m));
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cin >> dungeon[i][j];
            }
        }

        vector<vector<ll>> dp(n, vector<ll>(m, -1)); 
        cout << dfs(0, 0, dungeon, dp, n, m) << endl;
    }
    return 0;
}
