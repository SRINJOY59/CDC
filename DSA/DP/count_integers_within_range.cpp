#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
class Solution {
    int dp[30][2][2][500];
public:
    int rec(int level, int tlo, int thi, int sum, int min_sum, int max_sum, int n, string &num1, string &num2){
        if(level == n){
            if(sum >= min_sum && sum <= max_sum){
                return 1;
            }
            else return 0;
        }
        if(dp[level][tlo][thi][sum] != -1){
            return dp[level][tlo][thi][sum];
        }
        int ans = 0;
        int lo = 0;
        if(tlo == 1) lo = num1[level] - '0';
        int hi = 9;
        if(thi == 1) hi = num2[level] - '0';
        for(int i = lo;i<=hi;i++){
            int ntlo = tlo;
            if(i != num1[level] - '0'){
                ntlo = 0;
            }
            int nthi = thi;
            if(i != num2[level] - '0'){
                nthi = 0;
            }
            ans = (ans + rec(level+1, ntlo, nthi, sum+i, min_sum, max_sum, n, num1, num2))%MOD;
        }
        return dp[level][tlo][thi][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int n = num2.length();
        int padding = n - num1.length();
        string t = "";
        while(padding > 0){
            t += '0';
            padding--;
        }
        t += num1;
        return rec(0, 1, 1, 0, min_sum, max_sum, n, t, num2);
    }
};

int main(){
    string L, R;
    cin>>L>>R;
    int max_sum, min_sum;
    cin>>max_sum>>min_sum;
    Solution sol;
    cout<<sol.count(L, R, min_sum, max_sum)<<endl;
    return 0;
}