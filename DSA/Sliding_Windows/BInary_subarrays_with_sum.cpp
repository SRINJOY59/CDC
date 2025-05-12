#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAtMost(vector<int>& nums, int goal) {
        int n = nums.size();
        int start = 0;
        long long sum = 0;
        int ans = 0;

        for (int end = 0; end < n; ++end) {
            sum += nums[end];
            while (start <= end && sum > goal) {
                sum -= nums[start];
                start++;
            }
            ans += (end - start + 1); // all subarrays ending at 'end' with sum ≤ goal
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) return countAtMost(nums, 0); 
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};
