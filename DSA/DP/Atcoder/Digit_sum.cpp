#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int n, D;
int dp[10001][2][2][101]; 
string L, R;

int rec(int level, int tlo, int thi, int sumD){
    if(level == n){
        return (sumD == 0) ? 1 : 0;
    }
    if(dp[level][tlo][thi][sumD] != -1){
        return dp[level][tlo][thi][sumD];
    }

    int ans = 0;
    int lo = (tlo ? L[level] - '0' : 0);
    int hi = (thi ? R[level] - '0' : 9);

    for(int i = lo; i <= hi; i++){
        int ntlo = tlo && (i == lo);
        int nthi = thi && (i == hi);
        ans = (ans + rec(level + 1, ntlo, nthi, (sumD + i) % D)) % MOD;
    }

    return dp[level][tlo][thi][sumD] = ans;
}

int main(){
    cin >> R;
    cin >> D;
    n = R.length();
    L = string(n - 1, '0') + '1';  

    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 1, 1, 0);
    cout << ans << endl;
    return 0;
}
