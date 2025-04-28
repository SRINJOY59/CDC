#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll>&h, vector<ll>&s, ll idx, ll price, vector<vector<ll>>&dp){
    if(idx >= h.size()){
        return 0;
    }
    if(dp[idx][price] != -1){
        return dp[idx][price];
    }
    ll take = 0;
    ll notTake = 0;
    if(price >= h[idx]){
        take = s[idx] + solve(h, s, idx+1, price - h[idx], dp);
    }
    notTake = solve(h, s, idx+1, price, dp);
    return dp[idx][price] = max(take, notTake);
}

int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll>h(n);
    vector<ll>s(n);
    for(ll i = 0;i<n;i++){
        cin>>h[i];
    }
    for(ll i = 0;i<n;i++){
        cin>>s[i];
    }
    vector<ll>prev(x+1, 0);
    for(ll i = 0;i<n;i++){
        vector<ll>curr(x+1, 0);
        for(ll target = 0;target<=x;target++){
            ll take = 0;
            ll notTake = 0;
            if(target >= h[i]){
                take = s[i] + prev[target - h[i]];
            }
            notTake = prev[target];
            curr[target] = max(take, notTake);
        }
        prev = curr;
    }

    cout<<prev[x]<<endl;
    return 0;
}