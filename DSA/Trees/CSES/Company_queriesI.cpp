#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll maxN = 2e5+10;
ll logK = 20;
vector<vector<ll>>adj(maxN);
vector<vector<ll>>up(maxN, vector<ll>(logK, -1));

void binary_lifting(ll node, ll parent){
    up[node][0] = parent;
    for(ll i = 1;i<logK;i++){
        if(up[node][i-1] != -1)
            up[node][i] = up[up[node][i-1]][i-1];
        else
            up[node][i] = -1;
    }
    for(auto v: adj[node]){
        if(v != parent){
            binary_lifting(v, node);
        }
    }
}

ll get_kth_answer(ll node, ll k){
    for(ll i = 0;i<logK;i++){
        if((1<<i)&k){
            node = up[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin>>n>>q;
    for(ll i = 2;i<=n;i++){
        ll v;
        cin>>v;
        adj[v].push_back(i);
        adj[i].push_back(v);
    }
    binary_lifting(1, -1);
    while(q--){
        ll x, k;
        cin>>x>>k;
        ll ans = get_kth_answer(x, k);
        cout<<ans<<endl;
    }
    return 0;
}