#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll>dp(n+1, 0);
    for(ll i = 1;i<=6;i++){
        if(i <= n)
            dp[i] = 1;
    }
    for(ll target = 0;target<=n;target++){
        for(ll i = 1;i<=6;i++){
            if(i <= target){
                dp[target] = (dp[target] + dp[target - i])%MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}