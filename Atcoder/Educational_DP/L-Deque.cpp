#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(ll start, ll end, vector<ll>&stones, int flag, vector<vector<vector<ll>>>&dp){
    if(start > end){
        return 0;
    }
    if(dp[start][end][flag] != -1){
        return dp[start][end][flag];
    }

    if(flag == 0){
        return dp[start][end][flag] = max(stones[start] + solve(start+1, end, stones, 1, dp), stones[end] + solve(start, end-1, stones, 1, dp));
    }
    else{
        return dp[start][end][flag] = min(-stones[start] + solve(start+1, end, stones, 0, dp), -stones[end] + solve(start, end-1, stones, 0, dp));
    }
}


int main(){
    ll n;
    cin>>n;
    vector<ll>stones(n);
    for(ll i = 0;i<n;i++){
        cin>>stones[i];
    }
    vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    cout<<solve(0, n-1, stones, 0, dp)<<endl;
    return 0;  
}