#include<bits/stdc++.h>
using namespace std;

const int MOD = 10000003;

bool check(vector<int>&C, int B, int max_time){
    int cnt = 0;
    int tot = 0;
    int n = C.size();
    for(int i = 0;i<n;i++){
        if(tot + B*C[i] < max_time){
            tot += B*C[i];
        }
        else{
            cnt++;
            tot = B*C[i];
        }
    }
    return cnt <= n;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    int lo = 1;
    int hi = 0;
    for(int i = 0;i<n;i++){
        hi += B*C[i];
    }
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(check(C, B, mid)){
            ans = mid%MOD;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return ans;
}
