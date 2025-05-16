#include<bits/stdc++.h>
using namespace std;

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    int maxi = 0;
    for(int i = 0;i<A.size();i++){
        maxi = max(maxi, abs(A[i] - B[i]));
    }
    return maxi;
}
