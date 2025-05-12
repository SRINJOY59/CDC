#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[1001][1001];
int nextPos[1001][26];

void computeNext(const string &t) {
    int m = t.size();
    for (int c = 0; c < 26; ++c)
        nextPos[m][c] = m;

    for (int j = m - 1; j >= 0; --j) {
        for (int c = 0; c < 26; ++c)
            nextPos[j][c] = nextPos[j + 1][c];
        nextPos[j][t[j] - 'a'] = j;
    }
}

int solve(int i, int j, const string &s, const string &t) {
    if (i == s.length()) return INF;
    if (j == t.length()) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int option1 = solve(i + 1, j, s, t);
    int nextIdx = nextPos[j][s[i] - 'a'];
    int option2 = (nextIdx == t.length()) ? 1 : 1 + solve(i + 1, nextIdx + 1, s, t);

    return dp[i][j] = min(option1, option2);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s, t;
        cin >> s >> t;
        memset(dp, -1, sizeof(dp));
        computeNext(t);
        int res = solve(0, 0, s, t);
        if (res >= INF) cout << -1 << "\n";
        else cout << res << "\n";
    }
    return 0;
}
