#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& A, int B, int max_pages) {
    int cnt = 1;
    int tot = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > max_pages) return false;
        if (tot + A[i] <= max_pages) {
            tot += A[i];
        } else {
            tot = A[i];
            cnt++;
        }
    }
    return cnt <= B; 
}

int Solution::books(vector<int> &A, int B) {
    if (B > A.size()) return -1; 

    int low = *max_element(A.begin(), A.end());
    int high = 0;
    for(int i = 0;i<A.size();i++){
        high += A[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(A, B, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}