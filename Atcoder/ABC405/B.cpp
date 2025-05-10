#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> vis(m, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 1 && arr[i] <= m) {
            vis[arr[i] - 1] = 1;
        }
    }

    if (any_of(vis.begin(), vis.end(), [](int x) { return x == 0; })) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 1 && arr[i] <= m) {
            freq[arr[i]]++;
        }
    }

    int i = n - 1;
    int count = 0;
    while (i >= 0) {
        if (arr[i] >= 1 && arr[i] <= m) {
            freq[arr[i]]--;
            count++;
            if (freq[arr[i]] == 0) {
                freq.erase(arr[i]);
            }
        }
        if ((int)freq.size() < m) break;
        i--;
    }

    cout << count << endl;
    return 0;
}
