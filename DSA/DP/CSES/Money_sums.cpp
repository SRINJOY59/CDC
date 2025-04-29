#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>x(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin>>x[i];
        sum += x[i];
    }
    vector<int>dp(sum+1, 0);
    dp[0] = 1;
    for(int i = 0;i<n;i++){
        for(int s = sum;s >= x[i];s--){
            if(dp[s - x[i]])
                dp[s] = 1;
        }
    }
    int count = 0;
    for(int i = 1;i<=sum;i++){
        if(dp[i])
            count++;
    }
    cout<<count<<endl;
    for(int i = 1;i<=sum;i++){
        if(dp[i])
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}