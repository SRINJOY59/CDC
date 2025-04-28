#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
    deque<pair<ll, ll>> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;

    vector<ll> dx = {-1, 0, 1, 0};
    vector<ll> dy = {0, -1, 0, 1};

    while(!dq.empty()){
        ll curr_x = dq.front().first;
        ll curr_y = dq.front().second;

        dq.pop_front();
        for(ll i = 0;i<4;i++){
            ll x = curr_x + dx[i];
            ll y = curr_y + dy[i];

            if(x >= 0 && y >= 0 && x < n && y < m){
                if(grid[x][y] == '.'){
                    if(dist[x][y] > dist[curr_x][curr_y]){
                        dist[x][y] = dist[curr_x][curr_y];
                        dq.push_front({x, y});
                    }
                } else {
                    for(ll nx = x-1;nx<=x+1;nx++){
                        for(ll ny = y-1;ny<=y+1;ny++){
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                                if(dist[nx][ny] > dist[curr_x][curr_y] + 1){
                                    dist[nx][ny] = dist[curr_x][curr_y] + 1;
                                    dq.push_back({nx, ny});
                                }
                            }
                        }
                    }
                } 
            }
        }
    }

    ll ans = dist[n-1][m-1];
    cout<<(ans == LLONG_MAX ? -1 : ans)<<endl;
    return 0;
}