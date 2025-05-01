#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll>&arr){
    ll n = arr.size();
    vector<ll>dp(n, 0);
    ll maxi = 0;
    for(ll i = 0;i<n;i++){
        if(arr[i] == 1){
            if(i > 0){
                dp[i] = dp[i-1] + 1;
            }
            else
                dp[i] = 1;
            maxi = max(maxi, dp[i]);
        }
    }
    return maxi;
}

int main(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>grid(n, vector<ll>(m, 0));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<ll>maxi(n, 0);
    for(ll i = 0;i<n;i++){
        maxi[i] = solve(grid[i]);
    }
    while(q--){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        grid[x][y] = 1 - grid[x][y];
        maxi[x] = solve(grid[x]);
        ll ans = *max_element(maxi.begin(), maxi.end());
        cout<<ans<<endl;
    }
    return 0;
}