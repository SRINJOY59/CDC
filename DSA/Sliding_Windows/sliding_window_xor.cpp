#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin>>n>>k;
    ll x, a, b, c;
    cin>>x>>a>>b>>c;
    vector<ll>arr(n+1);
    arr[1] = x;
    for(ll i = 2;i<=n;i++){
        arr[i] = (a*arr[i-1] + b)%c;
    }
    vector<ll>Xors;
    ll Xor = 0;
    for(ll i = 1;i<=k;i++){
        Xor^= arr[i];
    }
    Xors.push_back(Xor);
    for(ll i = k+1;i<=n;i++){
        Xor^=arr[i-k];
        Xor^=arr[i];
        Xors.push_back(Xor);
    }
    ll ans = 0;
    for(ll i = 0;i<Xors.size();i++){
        ans^=Xors[i];
    }
    cout<<ans<<endl;
    return 0;
}