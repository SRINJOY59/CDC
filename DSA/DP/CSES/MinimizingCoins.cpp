#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll>&arr, ll idx, ll sum, vector<vector<ll>>&dp){
    if(idx == arr.size()){
        return sum == 0 ? 0 : INT_MAX;
    }
    if(sum < 0){
        return INT_MAX;
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    ll take = 1 + solve(arr, idx, sum - arr[idx], dp);
    ll notTake = solve(arr, idx + 1, sum, dp);

    return dp[idx][sum] = min(take, notTake);
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    vector<int>prev(x+1, 0);
    for(int target = 0;target <= x;target++){
        if(target%coins[0] == 0){
            prev[target] = target/coins[0];
        }
        else{
            prev[target] = 1e9;
        }
    }
    for(int i = 1;i<n;i++){
        vector<int>curr(x+1, 0);
        for(int target = 0;target <= x;target++){
            int notTake = prev[target];
            int take = 1e9;
            if(coins[i] <= target){
                take = 1 + curr[target - coins[i]];
            }
            int ans = min(notTake, take);
            curr[target] = ans;
        }
        prev = curr;
    }
    int ans = prev[x];
    if(ans == 1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}