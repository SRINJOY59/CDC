#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<ll> A(510);
vector<vector<ll>> dp(510, vector<ll>(510, -1));
vector<vector<ll>> sum(510, vector<ll>(510, 0));

ll get_sum(ll i, ll j) {
    return sum[i][j];
}

ll rec(ll L, ll R) {
    if (L == R) return 0;
    if (dp[L][R] != -1) return dp[L][R];

    ll ans = LLONG_MAX;
    for (ll k = L; k < R; k++) {
        ll left = rec(L, k);
        ll right = rec(k + 1, R);
        ll total = get_sum(L, k) * get_sum(k + 1, R);
        ans = min(ans, left + right + total);
    }

    return dp[L][R] = ans;
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        sum[i][i] = A[i];
    }

    // Precompute sum[i][j] = (A[i] + ... + A[j]) % 100
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            sum[i][j] = (sum[i][j - 1] + A[j]) % 100;
        }
    }

    cout << rec(1, n) << endl;
}

int main() {
    solve();
    return 0;
}
