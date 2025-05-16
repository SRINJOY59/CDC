#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int solve(int n, vector<int>&dp){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ways = 0;
    for(int i = 0;i<n;i++){
        ways = (ways + 1LL*solve(i, dp)*solve(n-1-i, dp))%MOD;
    }
    return dp[n] = ways;
}

int Solution::chordCnt(int A) {
    vector<int>dp(A+1, -1);
    return solve(A, dp);
}
