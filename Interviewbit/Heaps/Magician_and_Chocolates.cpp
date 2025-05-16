#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for(int chocolates : B){
        pq.push(chocolates);
    }

    long long ans = 0; 

    while (A-- && !pq.empty()) {
        int top = pq.top(); pq.pop();
        ans = (ans + top) % MOD;
        if (top / 2 > 0) pq.push(top / 2);
    }

    return ans;
}
