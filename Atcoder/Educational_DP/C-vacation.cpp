#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(ll idx, ll n, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<vector<ll>>&dp, ll prev){
    if(idx == n){
        return 0;
    }
    if(dp[idx][prev]!= -1){
        return dp[idx][prev];
    }
    ll ans = -1;
    for(int i = 1;i<=3;i++){
        if(prev != i){
            if(i == 1){
                ans = max(ans, solve(idx+1, n, a, b, c, dp, i) + a[idx]);
            }else if(i == 2){
                ans = max(ans, solve(idx+1, n, a, b, c, dp, i) + b[idx]);
            }
            else{
                ans = max(ans, solve(idx+1, n, a, b, c, dp, i) + c[idx]);
            }
        }
    }
    return dp[idx][prev] = ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(ll i = 0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(4, -1));

    cout<<solve(0, n, a, b, c, dp, 0)<<endl;
    return 0;
}