#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), comp);
    int ans = 1;
    int end = A[0][1];
    for(int i = 1;i<A.size();i++){
        if(A[i][0] > end){
            ans++;
            end = A[i][1];
        }
    }
    return ans;
}
