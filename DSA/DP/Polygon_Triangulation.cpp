#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    long long solve(vector<int>&values, int L, int R, vector<vector<long long>>&dp){
        if(R - L < 2)
            return 0;
        if(dp[L][R] != -1){
            return dp[L][R];
        }
        long long ans = INT_MAX;
        for(int mid = L+1;mid<R;mid++){
            ans = min(ans, solve(values, L, mid, dp) + solve(values, mid, R, dp) + values[L]*values[mid]*values[R]);
        }
        return dp[L][R] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<long long>>dp(n, vector<long long>(n, -1));
        return (int)solve(values, 0, n-1, dp);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.minScoreTriangulation(arr)<<endl;
    return 0;
}