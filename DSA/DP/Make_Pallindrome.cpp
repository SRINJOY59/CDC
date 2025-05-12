#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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


int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i < 0 || j < 0) return 0;  
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
    }
    else{
        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        string rev_str = "";
        for(int i = n-1;i>=0;i--){
            rev_str += s[i];
        }
        vector<vector<int>>dp(n, vector<int>(n, -1));
        cout<<n - solve(n-1, n-1, s, rev_str, dp)<<endl;
    }
    return 0;
}