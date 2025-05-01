#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll row, ll col, vector<ll>&pos){
    for(ll pr = 0;pr < row;pr++){
        ll pc = pos[pr];
        if(pc == col || pr == row || abs(pr - row) == abs(pc - col)){
            return false;
        }
    }
    return true;
}

ll solve(ll level, vector<vector<char>>&grid, vector<ll>&pos){
    if(level == 8)
        return 1;
    ll ans = 0;
    for(int col = 0;col<8;col++){
        if(grid[level][col] != '*'){
            if(check(level, col, pos)){
                pos[level] = col;
                ans += solve(level+1, grid, pos);
                pos[level] = -1;
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<char>>grid(8, vector<char>(8));
    vector<ll>position(8, -1);
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin>>grid[i][j];
        }
    }
    ll ans = solve(0, grid, position);
    cout<<ans<<endl;
    return 0;
}