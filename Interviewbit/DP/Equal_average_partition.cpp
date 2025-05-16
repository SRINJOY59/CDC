#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;
vector<int> res;

bool solve(int index, int curr_sum, int curr_size, vector<int>& A) {
    if (curr_size == 0) return curr_sum == 0;
    if (index >= A.size()) return false;

    if (dp[index][curr_sum][curr_size] != -1) return dp[index][curr_sum][curr_size];

    // Choose current element
    if (curr_sum >= A[index]) {
        res.push_back(A[index]);
        if (solve(index + 1, curr_sum - A[index], curr_size - 1, A))
            return dp[index][curr_sum][curr_size] = 1;
        res.pop_back();
    }

    // Skip current element
    if (solve(index + 1, curr_sum, curr_size, A))
        return dp[index][curr_sum][curr_size] = 1;

    return dp[index][curr_sum][curr_size] = 0;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int total_sum = 0;
    for(int i = 0;i<A.size();i++){
        total_sum += A[i];
    }

    for (int size1 = 1; size1 < n; ++size1) {
        if ((total_sum * size1) % n != 0) continue;

        int sum1 = (total_sum * size1) / n;
        dp = vector<vector<vector<int>>>(n + 1,vector<vector<int>>(sum1 + 1, vector<int>(size1 + 1, -1)));

        res.clear();
        if (solve(0, sum1, size1, A)) {
            vector<int> res1 = res;
            vector<int> res2;
            unordered_multiset<int> s(res1.begin(), res1.end());

            for (int val : A) {
                if (s.find(val) != s.end()) {
                    s.erase(s.find(val));
                } else {
                    res2.push_back(val);
                }
            }

            return {res1, res2};
        }
    }

    return {};
}
