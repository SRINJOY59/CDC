#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<vector<char>>&grid, ll i, ll j, vector<vector<ll>>&dp){
    if(i < 0 || j< 0 || i >= grid.size() || j >= grid[0].size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(grid[i][j] == '*'){
        return 0;
    }

    if(i == grid.size() - 1 && j == grid[0].size() - 1){
        return 1;
    }

    ll down = solve(grid, i+1, j, dp);
    ll right = solve(grid, i, j+1, dp);

    dp[i][j] = (down + right)%1000000007;
    return dp[i][j];
}

int main(){
    ll n;
    cin>>n;
    vector<vector<char>>grid(n, vector<char>(n));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>>dp(n, vector<ll>(n, -1));
    ll ans = solve(grid, 0, 0, dp);
    cout<<ans<<endl;
    return 0;
}