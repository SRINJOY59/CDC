#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double solve(vector<double>&probs, int idx, int count, vector<vector<double>>&dp){
    if(idx == probs.size()){
        if(2*count > probs.size()){
            return 1;
        }
        return 0;
    }   
    if(dp[idx][count] != -1){
        return dp[idx][count];
    }
    double ans = 0;
    ans = probs[idx]*solve(probs, idx+1, count+1, dp) + (1 - probs[idx])*solve(probs, idx+1, count, dp);
    return dp[idx][count] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<double>probs(n);
    for(int i = 0;i<n;i++){
        cin>>probs[i];
    }
    vector<vector<double>>dp(n+1, vector<double>(n+1, -1));
    double ans = solve(probs, 0, 0, dp);
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}