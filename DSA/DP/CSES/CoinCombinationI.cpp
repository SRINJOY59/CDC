#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll>coins(n);
    for(ll i = 0;i<n;i++){
        cin>>coins[i];
    }
    vector<ll>dp(x+1, 0);
    dp[0] = 1;
    for(ll target = 0;target<=x;target++){
        for(ll i = 0;i<n;i++){
            if(coins[i] <= target){
                dp[target] = (dp[target] + dp[target - coins[i]])%MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}