#include<bits/stdc++.h>
using namespace std;

int solve(int index, int hold, const vector<int>&A, vector<vector<int>>&dp){
    if(index == A.size()) return 0;
    if(dp[index][hold] != -1) return dp[index][hold];
    if(hold){
        int sell = A[index] + solve(index+1, 1 - hold, A, dp);
        int skip = solve(index+1, hold, A, dp);
        return dp[index][hold] = max(sell, skip);
    }
    else{
        int buy = -A[index] + solve(index+1, 1 - hold, A, dp);
        int skip = solve(index+1, hold, A, dp);
        return dp[index][hold] = max(buy, skip);
    }
}

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    vector<vector<int>>dp(n, vector<int>(2, -1));
    return solve(0, 0, A, dp);
}
