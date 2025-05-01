#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll idx, ll n, ll k, vector<ll>&heights, vector<ll>&dp){
    if(idx == n-1){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    ll ans = 1e18;
    for(ll i = 1;i<=k;i++){
        if(idx + i < n){
            ans = min(ans, abs(heights[idx+i] - heights[idx]) + solve(idx+i, n, k, heights, dp));
        }
    }
    return dp[idx] = ans;
}

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> h(n);
    for(ll i = 0;i<n;i++){
        cin>>h[i];
    }
    vector<ll> dp(n, -1);
    cout<<solve(0, n, k, h, dp)<<endl;
}