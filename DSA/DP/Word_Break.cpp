#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int dp[310];
unordered_set<string>dict;

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

int solve(int start){
    if(start == s.length()) return 1;
    if(dp[start] != -1) return dp[start];
    for(int end = start+1;end<=s.length();end++){
        if(dict.find(s.substr(start, end - start)) != dict.end() && solve(end)){
            return dp[start] = 1;
        }
    }
    return dp[start] = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        for(int i = 0;i<n;i++){
            string t;
            cin>>t;
            dict.insert(t);
        }
        memset(dp, -1, sizeof(dp));
        if(solve(0)) cout<<"Yes" <<endl;
        else cout<<"No"<<endl;
        dict.clear();
    }
    return 0;
}