#include<bits/stdc++.h>
using namespace std;

struct treenode {
    int lower;
    int upper;
    int count;
};

void build(vector<int>& arr, vector<treenode>& t, int index, int L, int R) {
    if (L == R) {
        t[index].lower = arr[L];
        t[index].upper = arr[L];
        t[index].count = 1;
        return;
    }
    int mid = (L + R) / 2;
    build(arr, t, 2 * index, L, mid);
    build(arr, t, 2 * index + 1, mid + 1, R);
    t[index].lower = min(t[2 * index].lower, t[2 * index + 1].lower);
    t[index].upper = max(t[2 * index].upper, t[2 * index + 1].upper);
    t[index].count = t[2 * index].count + t[2 * index + 1].count;
}

void update(vector<int>& arr, vector<treenode>& t, int index, int L, int R, int pos, int val) {
    if (pos < L || pos > R) return;
    if (L == R) {
        arr[L] = val;
        t[index].lower = val;
        t[index].upper = val;
        t[index].count = 1;
        return;
    }
    int mid = (L + R) / 2;
    update(arr, t, 2 * index, L, mid, pos, val);
    update(arr, t, 2 * index + 1, mid + 1, R, pos, val);
    t[index].lower = min(t[2 * index].lower, t[2 * index + 1].lower);
    t[index].upper = max(t[2 * index].upper, t[2 * index + 1].upper);
    t[index].count = t[2 * index].count + t[2 * index + 1].count;
}

int query(vector<int>& arr, vector<treenode>& t, int index, int L, int R, int a, int b) {
    if (R < a || L > b) return 0; 
    if (t[index].lower >= a && t[index].upper <= b) {
        return t[index].count; 
    }
    if (L == R) {
        return (arr[L] >= a && arr[L] <= b) ? 1 : 0; 
    }
    int mid = (L + R) / 2;
    return query(arr, t, 2 * index, L, mid, a, b) + query(arr, t, 2 * index + 1, mid + 1, R, a, b);
}

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<treenode> t(4 * n);
    build(arr, t, 1, 0, n - 1);
    while (Q--) {
        char ch;
        cin >> ch;
        if (ch == '!') {
            int pos, x;
            cin >> pos >> x;
            pos--;
            update(arr, t, 1, 0, n - 1, pos, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(arr, t, 1, 0, n - 1, a, b) + 1<< endl;
        }
    }
    return 0;
}
