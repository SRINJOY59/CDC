#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        map<char, int>mp;
        int start = 0;
        int end = 0;
        int n = s.length();
        while(start < n){
            while(end < n && !(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1)){
                mp[s[end]]++;
                end++;
            }
            if(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) ans += (n - end + 1);
            if(end > start){
                mp[s[start]]--;
                if(mp[s[start]] == 0){
                    mp.erase(s[start]);
                }
                start++;
            }
        }
        return ans;
    }
};