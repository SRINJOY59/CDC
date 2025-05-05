#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll n;

template<typename T>
vector<T> sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

ll solve(ll index, ll match, vector<vector<ll>>&dp){
    if(index == n) return 1;
    if(dp[index][match] != -1)
        return dp[index][match];

    if(match == 0){
        return dp[index][match] = (solve(index+1, 0, dp) + solve(index+1, 1, dp))%MOD;
    }
    else if(match == 1){
        return dp[index][match] = (solve(index+1, 1, dp) + solve(index+1, 2, dp))%MOD;
    }
    else if(match == 2){
        return dp[index][match] = (solve(index+1, 3, dp) + solve(index+1, 0, dp))%MOD;
    }
    else{
        return dp[index][match] = solve(index+1, 0, dp)%MOD;
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<ll>>dp(n, vector<ll>(4, -1));
        cout<<solve(0, 0, dp)<<endl;
    }
    return 0;
}