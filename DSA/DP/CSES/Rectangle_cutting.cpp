#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, vector<vector<ll>>&dp){

    if(a == 0 || b == 0){
        return 0;
    }
    if(a == b){
        return 0;
    }
    if(dp[a][b] != -1)
        return dp[a][b];
    ll ans = LLONG_MAX;
    for(ll i = 1;i<a;i++){
        ll res = 1 + solve(a-i, b, dp) + solve(i, b, dp);
        ans = min(ans, res);
    }
    for(ll i = 1;i<b;i++){
        ll res = 1 + solve(a, b-i, dp) + solve(a, i, dp);
        ans = min(ans, res);
    }
    return dp[a][b] = ans;
}

int main(){
    ll a, b;
    cin>>a>>b;
    vector<vector<ll>>dp(a+1, vector<ll>(b+1, LLONG_MAX));
    // cout<<solve(a, b, dp)<<endl;
    for(ll x = 0;x <= a;x++){
        for(ll y = 0;y<=b;y++){
            if(x == 0 || y == 0){
                dp[x][y] = 0;
            }
            else if(x == y){
                dp[x][y] = 0;
            }
            for(ll z = 1;z<x;z++){
                dp[x][y] = min(dp[x][y], 1 + dp[x-z][y] + dp[z][y]);
            }
            for(ll z = 1;z<y;z++){
                dp[x][y] = min(dp[x][y], 1 + dp[x][y - z] + dp[x][z]);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}