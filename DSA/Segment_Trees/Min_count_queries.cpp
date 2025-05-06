#include <bits/stdc++.h>
using namespace std;

struct treenode {
    int mini;
    int min_cnt;
    treenode(int m = 1e9, int cnt = 0){
        mini = m;
        min_cnt = cnt;
    }
};

void build(vector<int>& arr, vector<treenode>& t, int index, int L, int R) {
    if (L == R) {
        t[index].mini = arr[L];
        t[index].min_cnt = 1;
        return;
    }
    int mid = (L + R) / 2;
    build(arr, t, 2 * index, L, mid);
    build(arr, t, 2 * index + 1, mid + 1, R);

    int left_min = t[2 * index].mini;
    int right_min = t[2 * index + 1].mini;

    t[index].mini = min(left_min, right_min);
    t[index].min_cnt = 0;
    if (t[index].mini == left_min)
        t[index].min_cnt += t[2 * index].min_cnt;
    if (t[index].mini == right_min)
        t[index].min_cnt += t[2 * index + 1].min_cnt;
}

void update(vector<int>& arr, vector<treenode>& t, int index, int L, int R, int pos, int val) {
    if (pos < L || pos > R)
        return;
    if (L == R) {
        arr[L] = val;
        t[index].mini = val;
        t[index].min_cnt = 1;
        return;
    }
    int mid = (L + R) / 2;
    update(arr, t, 2 * index, L, mid, pos, val);
    update(arr, t, 2 * index + 1, mid + 1, R, pos, val);

    int left_min = t[2 * index].mini;
    int right_min = t[2 * index + 1].mini;

    t[index].mini = min(left_min, right_min);
    t[index].min_cnt = 0;
    if (t[index].mini == left_min)
        t[index].min_cnt += t[2 * index].min_cnt;
    if (t[index].mini == right_min)
        t[index].min_cnt += t[2 * index + 1].min_cnt;
}

pair<int, int> query(vector<treenode>& t, int index, int L, int R, int LQ, int RQ) {
    if (L > RQ || R < LQ)
        return {INT_MAX, 0};
    if (LQ <= L && R <= RQ)
        return {t[index].mini, t[index].min_cnt};
    
    int mid = (L + R) / 2;
    auto left = query(t, 2 * index, L, mid, LQ, RQ);
    auto right = query(t, 2 * index + 1, mid + 1, R, LQ, RQ);

    int minimum = min(left.first, right.first);
    int count = 0;
    if (left.first == minimum) count += left.second;
    if (right.first == minimum) count += right.second;

    return {minimum, count};
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<treenode> t(4 * n);
    build(arr, t, 1, 0, n - 1);

    int Q;
    cin >> Q;
    while (Q--) {
        int ch;
        cin >> ch;
        if (ch == 0) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(arr, t, 1, 0, n - 1, pos, val);
        } else if (ch == 1) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            auto res = query(t, 1, 0, n - 1, l, r);
            cout << "Min: " << res.first << ", Count: " << res.second << endl;
        }
    }

    return 0;
}
