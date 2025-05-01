#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll knapSack(ll index, ll W, vector<ll>& wt, vector<ll>& V, ll n, vector<vector<ll>>&dp){
    if(index >= n || W < 0){
        return 0;
    }
    if(dp[index][W] != -1){
        return dp[index][W];
    }
    if(wt[index] <= W){
        return dp[index][W] = max(V[index] + knapSack(index+1, W-wt[index], wt, V, n, dp), knapSack(index+1, W, wt, V, n, dp));
    }else{
        return dp[index][W] = knapSack(index+1, W, wt, V, n, dp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, wt;
    cin>>n>>wt;
    vector<ll>W(n);
    vector<ll>V(n);
    for(ll i = 0; i < n; i++){
        cin>>W[i]>>V[i];
    }
    vector<vector<ll>>dp(n, vector<ll>(wt+1, -1));
    cout<<knapSack(0, wt, W, V, n, dp)<<endl;
    return 0;
}