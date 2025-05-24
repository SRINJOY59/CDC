#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>FourSum(vector<ll>&arr, ll n, ll target){
    map<ll, pair<ll, ll>>pos;
    for(ll b = n-2;b>=1;b--){
        for(ll a = b-1;a>=0;a--){
            if(pos.find(target - arr[a] - arr[b]) != pos.end()){
                pair<ll, ll>ans = pos[target - arr[a] - arr[b]];
                return {a, b, ans.first, ans.second};
            }
        }
        ll c = b;
        for(ll d = c+1;d<n;d++){
            pos[arr[c]+arr[d]] = {c, d};
        }
    }
    return {-1};
}

int main(){
    ll n, target;
    cin>>n>>target;
    vector<ll>arr(n);
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>ans = FourSum(arr, n, target);
    if(ans.size() == 1) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}