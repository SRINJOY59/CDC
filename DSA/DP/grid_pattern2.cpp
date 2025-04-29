#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&mat, vector<vector<int>>&dp, int i, int j){
    if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()){
        return 0;
    }
    if(i == mat.size() - 1){
        return mat[i][j];
    }
    int down = solve(mat, dp, i+1, j);
    int leftDiag = solve(mat, dp, i+1, j-1);
    int rightDiag = solve(mat, dp, i+1, j+1);

    return dp[i][j] = mat[i][j] + max({down, leftDiag, rightDiag});
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>mat(n, vector<int>(m, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m, 0));
    for(int i = 0;i<m;i++){
        dp[0][i] = mat[0][i];
    }   
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            int up = dp[i-1][j];
            int leftDiag = (j > 0) ? dp[i-1][j-1] : 0;
            int rightDiag = (j < m-1) ? dp[i-1][j+1] : 0;
            dp[i][j] = mat[i][j] + max({up, leftDiag, rightDiag});
        }
    }
    int max_score = *max_element(dp[n-1].begin(), dp[n-1].end());
    vector<vector<int>>memo(n, vector<int>(m, -1));
    int max_score_memo = -1e9;
    for(int i = 0;i<m;i++){
        max_score_memo = max(max_score_memo, solve(mat, memo, 0, i));
    }
    cout<<max_score<<" "<<max_score_memo<<endl;
    return 0;

}