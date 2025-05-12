#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countAtleastK(vector<int>&nums, int k){
        int n = nums.size();
        int start = 0;
        int end = 0;
        int oddcnt = 0;
        int ans = 0;
        while(start < n){
            while(end < n && oddcnt < k){
                if(nums[end]&1) oddcnt++;
                end++;
            }
            if(oddcnt == k) ans += (n - end + 1);
            if(end > start){
                if(nums[start]&1)
                    oddcnt -= 1;
                start++;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtleastK(nums, k) - countAtleastK(nums, k+1);
    }
};