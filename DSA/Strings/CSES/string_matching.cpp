#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>kmp(string str){
    int n = str.length();
    vector<int>pi(n+1);
    pi[0] = -1;
    int i = 0, j = -1;
    while(i < n){
        while(j != -1 && str[i] != str[j]) j = pi[j];
        i++;
        j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string str, pattern;
    cin>>str;
    cin>>pattern;
    string s = pattern + "#" + str;
    vector<int>pi = kmp(s);
    int count = 0;
    for(int i = 0;i<pi.size();i++){
        if(pi[i] == pattern.length()){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}