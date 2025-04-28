#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>g[1000100];
vector<ll>vis(1000100, 0);
vector<ll>depth(1000100, 0);
vector<ll>parent(1000100, 0);
vector<ll>subtreeSz(1000100, 0);
vector<ll>numChild(1000100, 0);
vector<ll>isLeaf(1000100, 0);


void dfs(ll node, ll par, ll dep){
    depth[node] = dep;
    parent[node] = par;
    subtreeSz[node] = 1;
    numChild[node] = 0;
    for(auto v: g[node]){
        if(v != par){
            numChild[node] += 1;
            dfs(v, node, dep+1);
            subtreeSz[node] += subtreeSz[v];
        }
    }
    if(numChild[node] == 0){
        isLeaf[node] = 1;
    }
}

int main(){
    ll n;
    cin>>n;  //n is number of nodes and for trees there will be n-1 edges
    for(ll i = 0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    for(ll i = 1;i<=n;i++){
        cout<<i<<" "<<depth[i]<<" "<<parent[i]<<" "<<subtreeSz[i]<<" "<<numChild[i]<<" "<<isLeaf[i]<<endl;
    }
    //diameter of the tree
    ll maxNode = 1;
    for(ll i = 1;i<=n;i++){
        if(depth[i] > depth[maxNode]){
            maxNode = i;
        }
    }
    dfs(maxNode, 0, 0);

    ll diameter = 0;
    for(ll i = 1;i<=n;i++){
        diameter = max(diameter, depth[i]);
    }

    cout<<"Diameter of the tree is: "<<diameter<<endl;
    return 0;
}