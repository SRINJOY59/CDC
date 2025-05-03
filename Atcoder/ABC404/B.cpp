#include <bits/stdc++.h>
using namespace std;

int count_diff(const vector<string>& A, const vector<string>& B) {
    int N = A.size();
    int diff = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (A[i][j] != B[i][j])
                ++diff;
    return diff;
}

vector<string> rotate90(const vector<string>& grid) {
    int N = grid.size();
    vector<string> rotated(N, string(N, ' '));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            rotated[j][N - 1 - i] = grid[i][j];
    return rotated;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    for (int i = 0; i < N; ++i) cin >> T[i];

    int min_ops = INT_MAX;
    for (int r = 0; r < 4; ++r) {
        int flips = count_diff(S, T);
        int total_ops = flips + r; 
        min_ops = min(min_ops, total_ops);
        S = rotate90(S);
    }
    cout << min_ops<< '\n';
    return 0;
}
