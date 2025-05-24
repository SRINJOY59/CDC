#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& arr, int &res, vector<int>& answer) {
        if(index >= arr.size()) {
            answer.push_back(res);
            return;
        }
        res += arr[index];
        solve(index + 1, arr, res, answer);
        res -= arr[index];
        solve(index + 1, arr, res, answer);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> arr1, arr2;
        vector<int> answer1, answer2;
        int res1 = 0, res2 = 0;
        int n = nums.size();

        for(int i = 0; i < n / 2; i++) arr1.push_back(nums[i]);
        for(int i = n / 2; i < n; i++) arr2.push_back(nums[i]);

        solve(0, arr1, res1, answer1);
        solve(0, arr2, res2, answer2);

        sort(answer2.begin(), answer2.end());  
        int mini = INT_MAX;
        for(int i = 0; i < answer1.size(); i++) {
            int rem = goal - answer1[i];

            auto lb = lower_bound(answer2.begin(), answer2.end(), rem);
            if(lb != answer2.end()) {
                mini = min(mini, abs(*lb + answer1[i] - goal));
            }
            if(lb != answer2.begin()) {
                lb--;
                mini = min(mini, abs(*lb + answer1[i] - goal));
            }
        }

        return mini;
    }
};
