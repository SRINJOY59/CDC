#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
int dp[2001][2001];
int N, M, K;

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

int solve(int i, int k){
    if(k < 0) return 0;
    if(i == 1){
        if(k == 0) return M;
        else return 0;
    }
    if(dp[i][k] != -1) return dp[i][k];

    int same_color = solve(i-1, k) % MOD;
    int diff_color = (1LL * (M - 1) * solve(i - 1, k - 1)) % MOD;

    return dp[i][k] = (same_color + diff_color) % MOD;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>M>>K;
        memset(dp, -1, sizeof(dp));
        cout<<solve(N, K)<<endl;
    }
    return 0;
}