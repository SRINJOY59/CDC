#include<bits/stdc++.h>
using namespace std;
    
bool is_pallindrome(string &s, int start, int end){
    while(start < end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}
int solve(string &s, int idx, int n, vector<int>&dp){
    if(idx == n)
        return -1;
    if(dp[idx] != -1)
        return dp[idx];
        
    int ans = 1e9;
    for(int j = idx;j<n;j++){
        if(is_pallindrome(s, idx, j))
            ans = min(ans, 1 + solve(s, j+1, n, dp));
        }
    return dp[idx] = ans;
}
int minCut(string s) {
    int n = s.length();
    vector<int>dp(n, -1);
    return solve(s, 0, n, dp);
}

int main(){
    string str;
    cin>>str;
    cout<<minCut(str)<<endl;
    return 0;
}