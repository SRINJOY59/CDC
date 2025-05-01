#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll solve(ll sum, ll i, vector<vector<ll>>&dp){
    if(sum == 0) return 1;
    if(i == 0||sum < 0) return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    ll take = solve(sum-i, i-1, dp);
    ll notTake = solve(sum, i-1, dp);
    return dp[i][sum] = (take + notTake)%MOD;
}

int main(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll target = sum/2;
    vector<vector<ll>>dp(n+1, vector<ll>(target+1, -1));
    ll inverse_of_2 = (MOD + 1) / 2;
    ll ans = solve(target, n, dp);
    cout<<(ans*inverse_of_2)%MOD<<endl;
    return 0;
}