#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(2*n);
        ll S = 0;
        for(ll i = 0;i<2*n;i++){
            cin>>v[i];
            S += v[i];
        }
        ll c = 0;
        priority_queue<ll>pq;
        for(ll i = 0;i<2*n;i++){
            pq.push(v[i]);
            c += v[i];
            int m = (i + 1)/2;
            if((int)pq.size() > m){
                c -= pq.top();
                pq.pop();
            }
        }
        cout<<S - c<<endl;
    }
    return 0;
}