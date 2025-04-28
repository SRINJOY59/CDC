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
    // vector<vector<ll>>dp(n, vector<ll>(x+1, 0));
    vector<ll>prev(x+1, 0);
    for(ll i = 0;i<=x;i++){
        if(i%coins[0] == 0){
            prev[i] = 1;
        }
    }
    for(ll i = 1;i<n;i++){
        vector<ll>curr(x+1, 0);
        for(ll target = 0;target <= x;target++){
            ll notTake = prev[target];
            ll take = 0;
            if(coins[i] <= target){
                take = curr[target - coins[i]];
            }
            curr[target] = (notTake + take)%MOD;
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
    return 0;
}