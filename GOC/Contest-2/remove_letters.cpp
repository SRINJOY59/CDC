#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string str;
        cin>>str;
        map<char, int>mp;
        for(int i = 0;i<n;i++){
            mp[str[i]] += 1;
        }
        int ans = 0;
        vector<int>cnts;
        int mp_sz = mp.size();
        priority_queue<int>pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        while(m > 0 && !pq.empty()){
            int top = pq.top();
            pq.pop();
            top--;
            m--;
            if(top > 0){
                pq.push(top);
            }
        }
        while(!pq.empty()){
            int v = pq.top();
            ans += v*v;
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}