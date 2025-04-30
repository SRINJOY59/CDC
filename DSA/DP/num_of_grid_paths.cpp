#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll solve(vector<vector<ll>>& grid, ll i, ll j, ll k, vector<vector<vector<ll>>>& dp) {
    ll n = grid.size(), m = grid[0].size();
    
    if (i == n - 1 && j == m - 1) {
        return grid[i][j] == 1 ? (k > 0 ? 1 : 0) : 1;
    }

    if (dp[i][j][k] != -1) return dp[i][j][k];

    ll ans = 0;

    if (grid[i][j] == 1) {
        if (k == 0) return dp[i][j][k] = 0; // Cannot unblock
        if (i + 1 < n) ans = (ans + solve(grid, i + 1, j, k - 1, dp)) % MOD;
        if (j + 1 < m) ans = (ans + solve(grid, i, j + 1, k - 1, dp)) % MOD;
    } else {
        if (i + 1 < n) ans = (ans + solve(grid, i + 1, j, k, dp)) % MOD;
        if (j + 1 < m) ans = (ans + solve(grid, i, j + 1, k, dp)) % MOD;
    }

    return dp[i][j][k] = ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<ll>> grid(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(k + 1, -1)));
        cout << solve(grid, 0, 0, k, dp) << endl;
    }
    return 0;
}
