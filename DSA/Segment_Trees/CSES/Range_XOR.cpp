#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void build(vector<ll>&arr, vector<ll>&t, ll index, ll L, ll R){
    if(L == R){
        t[index] = arr[L];
        return ;
    }
    ll mid = (L + R)/2;
    build(arr, t, 2*index, L, mid);
    build(arr, t, 2*index + 1, mid+1, R);
    t[index] = t[2*index]^t[2*index+1];
}

void update(vector<ll>&arr, vector<ll>&t, ll index, ll L, ll R, ll pos, ll val){
    if(pos < L  || pos > R)
        return ;
    if(L == R){
        t[index] = val;
        arr[L] = val;
        return ;
    }
    ll mid = (L + R)/2;
    update(arr, t, 2*index, L, mid, pos, val);
    update(arr, t, 2*index+1, mid+1, R, pos, val);
    t[index] = t[2*index]^t[2*index+1];
}


ll query(vector<ll>&arr, vector<ll>&t, ll index, ll L, ll R, ll LQ, ll RQ){
    if(L > RQ || LQ > R){
        return 0;
    }
    //LQ <= L <= R <= RQ
    if(LQ <= L && R  <= RQ){
        return t[index];
    }
    ll mid = (L+R)/2;
    return query(arr, t, 2*index, L, mid, LQ, RQ)^query(arr, t, 2*index+1, mid+1, R, LQ, RQ);
}





int main(){
    ll n, Q;
    cin>>n>>Q;
    vector<ll>arr(n);
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>t(4*n);
    build(arr, t, 1, 0, n-1);
    while(Q--){
            ll LQ, RQ;
            cin>>LQ>>RQ;
            ll answer = query(arr, t, 1, 0, n-1, LQ-1, RQ-1);
            cout<<answer<<endl;
    }
    return 0;
}