#include<bits/stdc++.h>
using namespace std;

using ll = long long;
bool check(vector<int>&A, int B, int capacity){
    int cnt = 1;
    long long tot = 0;
    for(int i = 0;i<A.size();i++){
        if(A[i] > capacity) return false;
        if(tot + A[i] <= capacity){
            tot += A[i];
        }
        else{
            cnt++;
            tot = A[i];
        }
    }
    return cnt <= B;
}

int Solution::solve(vector<int> &A, int B) {
    int low = 0;
    int high = 0;
    int ans = -1;
    for(int i = 0;i<A.size();i++){
        high += A[i];
        low = max(low, A[i]);
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        if(check(A, B, mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return (int)ans;
}