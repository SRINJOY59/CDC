#include <bits/stdc++.h>
using namespace std;
using ll = long long;


pair<ll, ll> solve(vector<ll>& a, ll start, ll end, vector<vector<pair<ll, ll>>>& dp) {
    if (start == end) {
        return {a[start], 0};
    }
    if (dp[start][end].first != -1) {
        return dp[start][end];
    }

    auto opt1 = solve(a, start + 1, end, dp);
    ll score1 = a[start] + opt1.second;
    
    auto opt2 = solve(a, start, end - 1, dp);
    ll score2 = a[end] + opt2.second;

    if (score1 > score2) {
        dp[start][end] = {score1, opt1.first};
    } else {
        dp[start][end] = {score2, opt2.first};
    }

    return dp[start][end];
}

signed main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // pair<ll, ll> -> first element is current players score, second element is opponent's score

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {-1, -1}));
    auto res = solve(a, 0, n - 1, dp);
    cout << res.first - res.second << "\n";

    return 0;
}
