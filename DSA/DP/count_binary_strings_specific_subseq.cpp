#include<bits/stdc++.h>
using namespace std;


int n;
int dp[100100][5];

int rec(int level, int match){
    if(match == 4)
        return 0;
    if(level == n)
        return 1;
    if(dp[level][match] != -1) return dp[level][match];
    int ans = rec(level+1, match+1) + rec(level+1, match);
    return dp[level][match] = ans;
}

int main(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 0)<<endl;
    return 0;
}