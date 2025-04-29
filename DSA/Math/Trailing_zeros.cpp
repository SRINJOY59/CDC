#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    ll div = 5;
    while((n/div) > 0){
        ans += (n/div);
        div = div*5;
    }
    cout<<ans<<endl;
    return 0;
}