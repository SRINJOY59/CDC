#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s, t;
    cin>>s>>t;
    ll n1 = s.length();
    ll n2 = t.length();
    vector<vector<ll>>dp(n1+1, vector<ll>(n2+1, 0));
    for(int i = 1;i<=n2;i++){
        dp[0][i] = i; 
    }
    for(int i = 1;i<=n1;i++){
        dp[i][0] = i;
    }
    for(ll i = 1;i<=n1;i++){
        for(ll j = 1;j<=n2;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    cout<<dp[n1][n2]<<endl;
    return 0;
}