#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost = 1e18;

void solve(ll idx, vector<ll>& costs, vector<set<ll>>& adj, ll cost, ll m, map<ll, ll>& mp) {
    bool flag = true;
    for (auto elem : mp) {
        if (elem.second < 2) {
            flag = false;
            break;
        }
    }
    if (flag && mp.size() == m) {
        min_cost = min(min_cost, cost);
        return;
    }
    if (idx >= costs.size()) {
        return;
    }

    // not take
    solve(idx + 1, costs, adj, cost, m, mp);

    // take once
    for (auto animal : adj[idx]) {
        mp[animal]++;
    }
    solve(idx + 1, costs, adj, cost + costs[idx], m, mp);
    for (auto animal : adj[idx]) {
        mp[animal]--;
        if (mp[animal] == 0) mp.erase(animal);
    }

    // take twice 
    map<ll, ll> mp_twice = mp;
    for (auto animal : adj[idx]) {
        mp_twice[animal] += 2;
    }
    solve(idx + 1, costs, adj, cost + 2 * costs[idx], m, mp_twice);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> costs(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    vector<set<ll>> adj(n + 1);
    for (ll i = 1; i <= m; i++) {
        ll sz;
        cin >> sz;
        for (ll j = 0; j < sz; j++) {
            ll zoo;
            cin >> zoo;
            adj[zoo].insert(i);  
        }
    }

    map<ll, ll> mp;
    solve(1, costs, adj, 0, m, mp);
    cout << min_cost << endl;
    return 0;
}
