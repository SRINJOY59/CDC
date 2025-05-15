#include<bits/stdc++.h>
using namespace std;

bool dfs(int x, int y, vector<vector<char>>&grid, vector<vector<int>>&visited, int color){
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, -1, 0, 1};
    visited[x][y] = color;
    
    bool isEnclosed = true;
    
    if(x == 0 || y == 0 || x == grid.size()-1 || y == grid[0].size()-1){
        isEnclosed = false;
    }

    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()){
            if(grid[nx][ny] == 'O' && !visited[nx][ny]){
                if(!dfs(nx, ny, grid, visited, color)){
                    isEnclosed = false;
                }
            }
        }
    }
    
    return isEnclosed;
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>>visited(n, vector<int>(m, 0));
    int color = 1;
    vector<int>failed;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!visited[i][j] && A[i][j] == 'O'){
                if(!dfs(i, j, A, visited, color)){
                    failed.push_back(color);
                }
                color++;
            }
        }
    }
    for(int i = 0;i<failed.size();i++){
        int color = failed[i];
        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                if(visited[j][k] == color){
                    visited[j][k] = 0;
                    A[j][k] = 'O';
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] >= 1){
                A[i][j] = 'X';
            }
        }
    }
}
