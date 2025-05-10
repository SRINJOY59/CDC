#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>prefix(n);
    prefix[0] = arr[0];
    for(ll i = 1;i<n;i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ans += arr[i]*(prefix[n-1] - prefix[i]);
    }
    cout<<ans<<endl;
    return 0;
}