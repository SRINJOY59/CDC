#include <bits/stdc++.h>
using namespace std;

struct treenode {
    long long sum;       // Total sum of the segment
    long long prefix;    // Maximum prefix sum in the segment
    long long suffix;    // Maximum suffix sum in the segment
    long long max_sum;   // Maximum subarray sum in the segment
};

treenode merge(treenode l, treenode r) {
    treenode res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix, l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.max_sum = max({l.max_sum, r.max_sum, l.suffix + r.prefix});
    return res;
}

void build(vector<long long>& arr, vector<treenode>& t, long long index, long long L, long long R) {
    if (L == R) {
        long long x = max(arr[L], 0LL);
        t[index].sum = arr[L];
        t[index].prefix = x;
        t[index].suffix = x;
        t[index].max_sum = x;
        return;
    }
    long long mid = (L + R) / 2;
    build(arr, t, 2 * index, L, mid);
    build(arr, t, 2 * index + 1, mid + 1, R);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(vector<long long>& arr, vector<treenode>& t, long long index, long long L, long long R, long long pos, long long val) {
    if (pos < L || pos > R) return;
    if (L == R) {
        arr[L] = val;
        long long x = max(val, 0LL);
        t[index].sum = val;
        t[index].prefix = x;
        t[index].suffix = x;
        t[index].max_sum = x;
        return;
    }
    long long mid = (L + R) / 2;
    update(arr, t, 2 * index, L, mid, pos, val);
    update(arr, t, 2 * index + 1, mid + 1, R, pos, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, Q;
    cin >> n >> Q;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<treenode> t(4 * n + 1);
    build(arr, t, 1, 0, n - 1);

    while (Q--) {
        long long pos, val;
        cin >> pos >> val;
        pos--; 
        update(arr, t, 1, 0, n - 1, pos, val);
        cout << t[1].max_sum << '\n';
    }

    return 0;
}
