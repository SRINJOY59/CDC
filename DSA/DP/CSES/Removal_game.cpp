#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxi = -1;

void solve(vector<ll>&x, ll start, ll end, ll first, ll second, int flag){
    if(start > end){
        maxi = max(maxi, first);
        return ;
    }
    if(flag){
        first += x[start];
        solve(x, start+1, end, first, second, 1-flag);
        first -= x[start];

        first += x[end];
        solve(x, start, end-1, first, second, 1-flag);
        first -= x[end];
    }
    else{
        second += x[start];
        solve(x, start+1, end, first, second, 1-flag);
        second -= x[start];
        second += x[end];
        solve(x, start, end-1, first, second, 1-flag);
        second -= x[end];
    }
}


int main(){
    ll n;
    cin>>n;
    vector<ll>x(n);
    for(ll i = 0;i<n;i++){
        cin>>x[i];
    }
    ll first = 0;
    ll second = 0;
    ll start = 0;
    ll end = n-1;
    solve(x, start, end, first, second, 0);
    cout<<maxi<<endl;
    return 0;
}