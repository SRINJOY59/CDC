#include<bits/stdc++.h>
using namespace std;

string s;
int k, m;
char x, y;
vector<vector<int>> c(678, vector<int>(678, 0));

int dp[678][27][101];

int rec(int level, int prev_ch, int left) {
    if (left < 0) return -1e9;
    if (level == s.length()) return 0;

    if (dp[level][prev_ch][left] != -1) return dp[level][prev_ch][left];

    int ans = -1e9;
    int ch = s[level] - 'a';
    for (int i = 0; i < 26; i++) {
        if (i != ch) {
            ans = max(ans, rec(level + 1, i, left - 1) + c[prev_ch][i]);
        } else {
            ans = max(ans, rec(level + 1, i, left) + c[prev_ch][ch]);
        }
    }

    return dp[level][prev_ch][left] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> s >> k;
        cin >> m;

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                c[i][j] = 0;

        for (int i = 0; i < m; i++) {
            int w;
            cin >> x >> y >> w;
            c[x - 'a'][y - 'a'] = w;
        }

        memset(dp, -1, sizeof(dp));
        cout << rec(0, 26, k) << "\n";  // 26 as dummy prev_char
    }
    return 0;
}