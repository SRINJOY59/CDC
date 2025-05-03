#include<bits/stdc++.h>
using namespace std;


int main(){
    string str;
    cin>>str;
    vector<int>cnt(26, 0);
    for(int i = 0;i<str.length();i++){
        cnt[str[i] - 'a']++;
    }
    for(int i = 0;i<26;i++){
        if(!cnt[i]){
            cout<<(char)('a'+i)<<endl;
            return 0;
        }
    }
    return 0;
}