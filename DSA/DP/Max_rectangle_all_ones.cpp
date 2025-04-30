#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> nextSmaller(vector<ll>& arr) {
    ll n = arr.size();
    stack<ll> st;
    vector<ll> ans(n, n);
    for (ll i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<ll> prevSmaller(vector<ll>& arr) {
    ll n = arr.size();
    stack<ll> st;
    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

ll largestSquareHistogram(vector<ll>& arr) {
    vector<ll> prev = prevSmaller(arr);
    vector<ll> next = nextSmaller(arr);
    ll maxi = 0;
    for (ll i = 0; i < arr.size(); i++) {
        ll height = arr[i];
        ll width = next[i] - prev[i] - 1;
        ll side = min(height, width);
        maxi = max(maxi, side * side);
    }
    return maxi;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<ll> height(m, 0);
        ll maxi = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            maxi = max(maxi, largestSquareHistogram(height));
        }

        cout << maxi << endl;
    }
    return 0;
}
