#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll>&dp){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return INT_MAX;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    ll ans = INT_MAX;
    vector<ll>digits;
    ll temp = n;
    while(temp > 0){
        ll digit = temp % 10;
        if(digit != 0)
            ans = min(ans, 1 + solve(n - digit, dp));
        temp /= 10;
    }
    return dp[n] = ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll>dp(n + 1, -1);
    ll ans = solve(n, dp);
    cout<<ans<<endl;
    return 0;
}