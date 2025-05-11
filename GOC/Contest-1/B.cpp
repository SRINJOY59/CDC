#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> layers(n);
    vector<ll> energy(n);

    for (ll i = 0; i < n; i++) {
        cin >> layers[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> energy[i];
    }
    int start = 0;
    int end = 0;
    ll points = 0;
    ll power = k;
    while(start < n){
        while(end < n && power >= layers[end] && (power - layers[end]) >= energy[end]){
            power -= layers[end];
            end++;
            points++;
        }
        cout<<points<<" ";
        if(start < end){
            power += layers[start];
            points--;
        }
        else{
            end = start + 1;
            power = k;
            points = 0;
        }
        start++;
    }
    cout<<endl;

    return 0;
}
