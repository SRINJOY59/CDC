#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll h, w;
ll totalXOR = 0;
vector<vector<ll>>visited;

ll dfs(ll i, ll j, vector<vector<ll>>&A, ll currXOR){
    if(i == h) return currXOR;
    if(j == w) return dfs(i+1, 0, A, currXOR);
    if(visited[i][j]) return dfs(i, j+1, A, currXOR);

    ll res = dfs(i, j+1, A, currXOR);

    if(i + 1 < h && !visited[i+1][j]){
        visited[i][j] = visited[i+1][j] = 1;
        res = max(res, dfs(i, j+1, A, currXOR^A[i][j]^A[i+1][j]));
        visited[i][j] = visited[i+1][j] = 0;
    }
    if(j + 1 < w && !visited[i][j+1]){
        visited[i][j] = visited[i][j+1] = 1;
        res = max(res, dfs(i, j+2, A, currXOR^A[i][j]^A[i][j+1]));
        visited[i][j] = visited[i][j+1] = 0;
    }
    return res;
}

int main(){
    cin>>h>>w;
    vector<vector<ll>>grid(h, vector<ll>(w));
    for(ll i = 0;i<h;i++){
        for(ll j = 0;j<w;j++){
            cin>>grid[i][j];
            totalXOR = totalXOR^grid[i][j];
        }
    }

    visited.assign(h, vector<ll>(w, 0));
    ll ans = dfs(0, 0, grid, totalXOR);
    cout<<ans<<endl;
    return 0;
}