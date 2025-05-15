#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>&A, int mid, int req){
    int cnt = 0;
    for(int i = 0;i<A.size();i++){
        cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
    }
    return cnt >= req;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MAX;
    int high = 0;
    int r = A.size();
    int c = A[0].size();
    for(int i = 0;i<r;i++){
        low = min(low, A[i][0]);
        high = max(high, A[i][c-1]);
    }
    int req = (r*c + 1)/2;
    while(low < high){
        int mid = low + (high - low)/2;
        if(check(A, mid, req)){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}