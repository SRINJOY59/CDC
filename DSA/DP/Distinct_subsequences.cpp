#include<bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
    string str;
    cin>>str;
    int n = str.length();
    vector<int>dp(n+1);
    vector<int>sum(n+1);
    dp[0] = 1;
    sum[0] = 1;
    int last[26];
    memset(last, -1, sizeof(last));
    for(int i = 1;i<=n;i++){
        dp[i] = sum[i-1];
        if(last[str[i-1]-'a'] > 0){
            dp[i] -= sum[last[str[i-1]-'a']-1];
        }
        last[str[i-1]-'a'] = i;
        sum[i] = dp[i] + sum[i-1];
    }
    cout<<sum[n]<<endl;  //considers empty string
    return 0;
}