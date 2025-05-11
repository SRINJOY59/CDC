#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>arr(n);
        vector<ll>suffix(n);
        for(ll i = 0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        suffix[n-1] = arr[n-1];
        for(ll i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + arr[i];
        }
        ll ans = 0;
        for(ll i = n-1;i>=0;i--){
            if(suffix[i] > 0)
                ans += suffix[i];
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}