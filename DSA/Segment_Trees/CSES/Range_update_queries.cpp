#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q;
vector<ll> a;
struct node
{
    ll sum;
    node(ll x = 0)
    {
        sum = x;
    }
};
vector<node> tree;
node merge(node a, node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        tree[id].sum = 0;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        tree[id].sum += val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}
node query(ll id, ll l, ll r, ll lq, ll rq)
{
    if (l > rq || r < lq)
        return node(0LL);
    if (lq <= l && r <= rq)
        return tree[id];
    ll mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    a.resize(n);
    tree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            update(1, 0, n - 1, a, u);
            update(1, 0, n - 1, b + 1, -u);
        }
        else
        {
            ll k;
            cin >> k;
            k--;
            node ans = query(1, 0, n - 1, 0, k);
            cout << ans.sum + a[k] << endl;
        }
    }
    return 0;
}