#include<bits/stdc++.h>
using namespace std;


int solve(int index, vector<int>&arr, vector<int>&dp){
    if(index >= arr.size()){
        return 0;
    }
    if(dp[index] != -1) return dp[index];
    int ans = max(arr[index] + solve(index+2, arr, dp), solve(index+1, arr, dp));
    return dp[index] = ans;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>dp(n, -1);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(0, arr, dp)<<endl;
    }
    return 0;
}