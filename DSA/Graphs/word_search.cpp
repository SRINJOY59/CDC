#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if (visited[r][c] || board[r][c] != word[idx]) return false;

        visited[r][c] = true;

        // Explore 4 directions: up, down, left, right
        bool found = dfs(board, word, r + 1, c, idx + 1, visited) ||
                     dfs(board, word, r - 1, c, idx + 1, visited) ||
                     dfs(board, word, r, c + 1, idx + 1, visited) ||
                     dfs(board, word, r, c - 1, idx + 1, visited);

        visited[r][c] = false;  // backtrack

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
