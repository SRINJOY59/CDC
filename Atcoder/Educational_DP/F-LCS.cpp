#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
    if(i == s.size() || j == t.size()){
        return 0;
    }
    if(dp[i][j]!= -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = 1 + solve(i+1, j+1, s, t, dp);
    }
    else{
        return dp[i][j] = max(solve(i+1, j, s, t, dp), solve(i, j+1, s, t, dp));
    }
}

int main(){
    string s, t;
    cin >> s >> t;

    vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));

    int len = solve(0, 0, s, t, dp);

    string ans = "";
    int i = 0 , j = 0;
    while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){
            ans += s[i];
            i++;
            j++;
        }
        else
        {
            if(dp[i+1][j]>=dp[i][j+1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}