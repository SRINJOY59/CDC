#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, D, M;
string A, B;
int dp[2001][2][2][2001];


int rec(int level, bool tightL, bool tightR, int mod) {
    if(level == n) return (mod == 0);

    if(dp[level][tightL][tightR][mod] != -1)
        return dp[level][tightL][tightR][mod];

    int lo = tightL ? A[level] - '0' : 0;
    int hi = tightR ? B[level] - '0' : 9;

    int ans = 0;
    for(int i = lo; i <= hi; ++i) {
        int pos = level + 1;
        if(i == D && pos % 2 == 1) continue;
        if(i != D && pos % 2 == 0) continue;

        bool newTightL = tightL && (i == lo);
        bool newTightR = tightR && (i == hi);

        int newMod = (mod * 10 + i) % M;

        ans = (ans + rec(level + 1, newTightL, newTightR, newMod)) % MOD;
    }

    return dp[level][tightL][tightR][mod] = ans;
}


int main(){
    cin >> M >> D;
    cin >> A >> B;
    memset(dp, -1, sizeof(dp));
    n = A.length();
    cout << rec(0, 1, 1, 0) << endl;
    return 0;
}
