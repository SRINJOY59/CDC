#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll R, B, r, b;
ll dp[101][101][11][11];


ll solve(ll red, ll black, ll consecR, ll consecB){
    if(red == 0 && black == 0) return 1;
    if(dp[red][black][consecR][consecB] != -1)
        return dp[red][black][consecR][consecB];
    ll ans = 0;
    if(red > 0 && consecR < r){
        ans = (ans + solve(red-1, black, consecR+1, 0))%MOD;
    }
    if(black > 0 && consecB < b){
        ans = (ans + solve(red, black-1, 0, consecB+1))%MOD;
    }
    return dp[red][black][consecR][consecB] = ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>R>>r>>B>>b;
        cout<<solve(R, B, 0, 0)<<endl;
    }
    return 0;
}