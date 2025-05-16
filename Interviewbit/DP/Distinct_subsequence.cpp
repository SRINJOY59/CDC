#include<bits/stdc++.h>
using namespace std;

int solve(string &A, string &B, int i, int j, vector<vector<int>>&dp){
    if (j == B.length()) return 1;  // Found a valid match
    if (i == A.length()) return 0;  // No more characters in A to match B
    
    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] == B[j]) {
        // Option 1: match A[i] with B[j], move both forward
        // Option 2: skip A[i], keep B[j] (look for another match)
        return dp[i][j] = solve(A, B, i + 1, j + 1, dp) + solve(A, B, i + 1, j, dp);
    } else {
        // Characters don't match, skip A[i]
        return dp[i][j] = solve(A, B, i + 1, j, dp);
    }
}

int Solution::numDistinct(string A, string B) {
    int n = A.length();
    int m = B.length();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return solve(A, B, 0, 0, dp);
}
