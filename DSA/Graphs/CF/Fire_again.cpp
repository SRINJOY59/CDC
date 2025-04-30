#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, m;
    cin >> n >> m;
    ll k;
    cin >> k;

    queue<pair<ll, pair<ll, ll>>> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(m + 1, 1e18));

    for (ll i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        q.push({0, {x, y}});
        dist[x][y] = 0;
    }

    vector<ll> dx = {-1, 0, 1, 0};
    vector<ll> dy = {0, -1, 0, 1};

    while (!q.empty()) {
        ll curr_x = q.front().second.first;
        ll curr_y = q.front().second.second;
        ll cost = q.front().first;
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll nx = curr_x + dx[i];
            ll ny = curr_y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] > dist[curr_x][curr_y] + 1) {
                dist[nx][ny] = dist[curr_x][curr_y] + 1;
                q.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    ll ans_x = -1, ans_y = -1, maxi = -1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (dist[i][j] > maxi) {
                maxi = dist[i][j];
                ans_x = i;
                ans_y = j;
            }
        }
    }

    cout << ans_x << " " << ans_y << endl;
    return 0;
}
