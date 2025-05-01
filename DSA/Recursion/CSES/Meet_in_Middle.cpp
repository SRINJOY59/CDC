#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll>generate(vector<ll>&arr){
    ll n = arr.size();
    vector<ll>subvals;
    for(int mask = 0;mask<(1<<n);mask++){
        ll sum = 0;
        for(ll j = 0;j<n;j++){
            if((mask>>j)&1)
                sum += arr[j];
        }
        subvals.push_back(sum);
    }
    sort(subvals.begin(), subvals.end());
    return subvals;
}

int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll>arr(n);
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>new_arr[2];
    for(ll i = 0;i<n;i++){
        new_arr[i&1].push_back(arr[i]);
    }
    vector<ll>sub1 = generate(new_arr[0]);
    vector<ll>sub2 = generate(new_arr[1]);
    ll ans = 0;
    for(auto elem : sub1){
        ll lower = lower_bound(sub2.begin(), sub2.end(), x - elem) - sub2.begin();
        ll upper = upper_bound(sub2.begin(), sub2.end(), x - elem) - sub2.begin();
        ans += upper - lower;
    }
    cout<<ans<<endl;
    return 0;
}