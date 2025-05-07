#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<int>>&arr, vector<vector<int>>&visited){
    int n = arr.size();
    int m = arr[0].size();
    visited[x][y] = 1;
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, -1, 0, 1};
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] >= arr[x][y] && !visited[nx][ny]){
            dfs(nx, ny, arr, visited);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>>red(n, vector<int>(m, 0));
    vector<vector<int>>blue(n, vector<int>(m, 0));
    for(int i = 0;i<n;i++){
        dfs(i, 0, A, blue);
        dfs(i, m-1, A, red);
    }
    for(int j = 0;j<m;j++){
        dfs(0, j, A, blue);
        dfs(n-1, j, A, red);
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(red[i][j] && blue[i][j])
                count++;
        }
    }
    return count;
}
void dfs(int x, int y, vector<vector<int>>&arr, vector<vector<int>>&visited){
    int n = arr.size();
    int m = arr[0].size();
    visited[x][y] = 1;
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, -1, 0, 1};
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] >= arr[x][y] && !visited[nx][ny]){
            dfs(nx, ny, arr, visited);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>>red(n, vector<int>(m, 0));
    vector<vector<int>>blue(n, vector<int>(m, 0));
    for(int i = 0;i<n;i++){
        dfs(i, 0, A, blue);
        dfs(i, m-1, A, red);
    }
    for(int j = 0;j<m;j++){
        dfs(0, j, A, blue);
        dfs(n-1, j, A, red);
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(red[i][j] && blue[i][j])
                count++;
        }
    }
    return count;
}
