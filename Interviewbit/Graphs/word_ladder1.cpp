#include<bits/stdc++.h>
using namespace std;

int Solution::solve(string A, string B, vector<string> &C) {
    queue<pair<string, int>>q;
    set<string>st(C.begin(), C.end());
    q.push({A, 1});
    st.erase(A);
    while(!q.empty()){
        string str = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(str == B){
            return steps;
        }
        for(int i = 0;i<str.length();i++){
            char original = str[i];
            for(char ch = 'a';ch<='z';ch++){
                str[i] = ch;
                if(st.find(str) != st.end()){
                    st.erase(str);
                    q.push({str, steps+1});
                }
            }
            str[i] = original;
        }
    }
    return 0;
}
