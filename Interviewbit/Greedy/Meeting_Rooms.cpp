#include<bits/stdc++.h>
using namespace std;

int Solution::solve(vector<vector<int> > &A) {
    vector<pair<int, int>>intervals;
    for(auto elem : A){
        intervals.push_back({elem[0], 1});
        intervals.push_back({elem[1], -1});
    }
    sort(intervals.begin(), intervals.end());
    int max_cnt = 0;
    int curr_cnt = 0;
    for(auto events: intervals){
        curr_cnt += events.second;
        max_cnt = max(max_cnt, curr_cnt);
    }
    return max_cnt;
}
