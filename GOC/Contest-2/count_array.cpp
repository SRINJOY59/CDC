#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll count_valid_permutations(vector<ll>& a, vector<ll>& b) {
    ll n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 1;
    for(ll i = 0;i<a.size();i++){
        ll lower_bnd = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans = (ans * (lower_bnd - i))%MOD;
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(ll &x : a) cin >> x;
        for(ll &x : b) cin >> x;
        cout << count_valid_permutations(a, b) << "\n";
    }
    return 0;
}
