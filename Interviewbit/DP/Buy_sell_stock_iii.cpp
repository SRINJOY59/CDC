#include<bits/stdc++.h>
using namespace std;

int solve(int index, const vector<int>&A, int transaction, int hold, vector<vector<vector<int>>>&dp){
    if(index == A.size() || transaction == 0){
        return 0;
    }
    if(dp[index][transaction][hold] != -1) return dp[index][transaction][hold];
    if(hold){
        int sell = A[index] + solve(index+1, A, transaction-1, 1 - hold, dp);
        int skip = solve(index+1, A, transaction, hold, dp);
        return dp[index][transaction][hold] = max(sell, skip); 
    }
    else{
        int buy = -A[index] + solve(index+1, A, transaction, 1 - hold, dp);
        int skip = solve(index+1, A, transaction, hold, dp);
        return dp[index][transaction][hold] = max(buy, skip);
    }
}

int Solution::maxProfit(const vector<int> &A) {
    int max_transaction = 2;
    int n = A.size();
    vector<vector<int>>prev(max_transaction+1, vector<int>(2, 0));
    vector<vector<int>>curr(max_transaction+1, vector<int>(2, 0));
    for(int index = n-1;index>=0;index--){
        for(int transaction = 1;transaction<=max_transaction;transaction++){
            for(int hold = 0;hold<=1;hold++){
                if(hold){
                    curr[transaction][hold] = max(A[index] + prev[transaction-1][1-hold], prev[transaction][hold]);
                }
                else{
                    curr[transaction][hold] = max(-A[index] + prev[transaction][1-hold], prev[transaction][hold]);
                }
            }
        }
        prev = curr;
    }
    return prev[max_transaction][0];
}