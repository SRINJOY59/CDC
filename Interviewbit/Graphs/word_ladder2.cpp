#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    unordered_set<string>st(dict.begin(), dict.end());
    queue<vector<string>>q;
    q.push({start});
    vector<string>UsedOnLevel;
    int level = 0;
    UsedOnLevel.push_back(start);
    vector<vector<string>>ans;
    while(!q.empty()){
        vector<string>vec = q.front();
        q.pop();
        if(vec.size() > level){
            level++;
            for(auto elem: UsedOnLevel){
                st.erase(elem);
            }
        }
        string word = vec.back();
        if(word == end){
            ans.push_back(vec);
        }
        for(int i = 0;i<word.length();i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    vec.push_back(word);
                    UsedOnLevel.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;    
}