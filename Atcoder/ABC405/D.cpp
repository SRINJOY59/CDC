#include<bits/stdc++.h>
using namespace std;

vector<int>dx = {-1, 0, 1, 0};
vector<int>dy = {0, -1, 0, 1};
vector<char>dir = {'^', '<', 'v', '>'};
vector<char>rev_dir = {'v', '>', '^', '<'};

int main(){
    int h, w;
    cin>>h>>w;
    vector<vector<char>>grid(h, vector<char>(w));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<int, int>>q;
    vector<vector<int>>visited(h, vector<int>(w, 0));
    vector<vector<char>>answer(h, vector<char>(w));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            if(grid[i][j] == 'E'){
                q.push({i, j});
                visited[i][j] = 1;
                answer[i][j] = 'E';
            }
            if(grid[i][j] == '#'){
                answer[i][j] = '#';
            }
        }
    }

    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == '.' && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                answer[nx][ny] = rev_dir[i];
            }
        }
    }
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cout<<answer[i][j];
        }
        cout<<endl;
    }
    return 0;
}