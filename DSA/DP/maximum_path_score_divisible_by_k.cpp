#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll NEG_INF = LLONG_MIN;
int n, m, k;
int a[101][101];
ll dp[101][101][12]; // dp[row][col][remainder]

ll solve(int i, int j, int rem) {
    if (j < 1 || j > m) return NEG_INF;

    if (i == 0) {
        int new_rem = (a[i][j] + rem) % k;
        if (new_rem == 0) return a[i][j] + rem;
        else return NEG_INF;
    }

    if (dp[i][j][rem] != -1) return dp[i][j][rem];

    int new_rem = (rem + a[i][j]) % k;
    ll left = solve(i - 1, j - 1, new_rem);
    ll right = solve(i - 1, j + 1, new_rem);

    ll best = max(left, right);

    if (best == NEG_INF) return dp[i][j][rem] = NEG_INF;
    else return dp[i][j][rem] = best + a[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }

        memset(dp, -1, sizeof(dp));

        ll result = NEG_INF;
        for (int j = 1; j <= m; ++j) {
            ll res = solve(n, j, 0);  
            result = max(result, res);
        }

        cout << (result == NEG_INF ? -1 : result) << "\n";
    }

    return 0;
}
