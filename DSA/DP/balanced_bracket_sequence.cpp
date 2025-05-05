#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

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

ll solve(string &str, ll idx, ll balance, vector<vector<ll>>& dp) {
    if (balance < 0) return 0; // invalid state
    if (idx == str.length()) return balance == 0 ? 1 : 0;
    if (dp[idx][balance] != -1) return dp[idx][balance];

    ll res = 0;
    if (str[idx] == '(') {
        res = solve(str, idx + 1, balance + 1, dp);
    } else if (str[idx] == ')') {
        if (balance > 0)
            res = solve(str, idx + 1, balance - 1, dp);
        else
            res = 0;
    } else { // '?'
        res = solve(str, idx + 1, balance + 1, dp); // as '('
        if (balance > 0)
            res = (res + solve(str, idx + 1, balance - 1, dp)) % MOD; // as ')'
    }

    return dp[idx][balance] = res % MOD;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        ll n = str.length();
        vector<vector<ll>>dp(n, vector<ll>(n+1, -1));
        cout<<solve(str, 0, 0, dp)<<endl;
    }
    return 0;
}