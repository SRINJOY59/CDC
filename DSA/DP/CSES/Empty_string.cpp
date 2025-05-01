#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 305;

ll dp[MAXN][MAXN];

ll countWays(string &s, int l, int r) {
    if (l > r) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    ll ways = 0;

    for (int i = l; i < r; ++i) {
        if (s[i] == s[i + 1]) {
            ll left = countWays(s, l, i - 1);
            ll middle = countWays(s, i + 2, r);
            ways += left + middle;
        }
    }

    return dp[l][r] = ways;
}

int main() {
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << countWays(s, 0, s.size() - 1) << endl;
    return 0;
}
