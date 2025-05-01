#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll>&x,ll k, vector<ll>&dp){
    if(k == 0){
        return 0;
    }
    if(dp[k] != -1){
        return dp[k];
    }
    ll ans = 0;
    for(ll i = 0;i<x.size();i++){
        if(k >= x[i]){
            if(solve(x, k - x[i], dp) == 0){
                ans = 1;
                break;
            }
        }
    }
    return dp[k] = ans;
}

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll>x(n);
    for(ll i = 0;i<n;i++){
        cin>>x[i];
    }
    vector<ll>dp(k+1, -1);
    ll ans = solve(x, k, dp);
    if(ans)
        cout<<"First"<<endl;
    else    
        cout<<"Second"<<endl;
    return 0;
}