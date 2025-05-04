#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& x, vector<int>& y, int L, int R,
              vector<vector<int>>& dp, vector<vector<int>>& back) {
        if (L == R)
            return 0;
        if (dp[L][R] != -1)
            return dp[L][R];

        int ans = INT_MAX;
        for (int mid = L; mid < R; ++mid) {
            int left = solve(x, y, L, mid, dp, back);
            int right = solve(x, y, mid + 1, R, dp, back);
            int cost = x[L] * y[mid] * y[R];
            if (left + right + cost < ans) {
                ans = left + right + cost;
                back[L][R] = mid;
            }
        }
        return dp[L][R] = ans;
    }

    void generate(int L, int R, vector<int>& opb, vector<int>& clb,
                  vector<vector<int>>& back) {
        if (L == R) return;
        opb[L]++;
        clb[R]++;
        int mid = back[L][R];
        generate(L, mid, opb, clb, back);
        generate(mid + 1, R, opb, clb, back);
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<int> x(n - 1), y(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            x[i] = arr[i];
            y[i] = arr[i + 1];
        }

        vector<vector<int>> dp(n - 1, vector<int>(n - 1, -1));
        vector<vector<int>> back(n - 1, vector<int>(n - 1, 0));
        vector<int> opb(n - 1, 0), clb(n - 1, 0);

        int ans = solve(x, y, 0, n - 2, dp, back);
        cout << ans << endl;

        generate(0, n - 2, opb, clb, back);

        for (int i = 0; i < n - 1; ++i) {
            for (int k = 0; k < opb[i]; ++k) cout << "(";
            cout << " " << (i + 1) << " ";
            for (int k = 0; k < clb[i]; ++k) cout << ")";
        }
        cout << " " << n<<endl; 

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    sol.matrixMultiplication(arr);
    return 0;
}
