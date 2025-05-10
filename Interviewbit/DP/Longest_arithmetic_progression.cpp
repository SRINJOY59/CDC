#include<bits/stdc++.h>
using namespace std;


int Solution::solve(const vector<int> &arr) {
    int n = arr.size();

    if (n <= 2) 
        return n;

    int ans = 2;

    vector<unordered_map<int, int>>dp(n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = arr[i] - arr[j];
            if(dp[j].count(diff))
                dp[i][diff] = 1 + dp[j][diff];
            else dp[i][diff] = 2; 
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

