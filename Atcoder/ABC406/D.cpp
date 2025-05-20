#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll H, W, N;
    cin>>H>>W>>N;
    map<int, multiset<int>>rows;
    map<int, multiset<int>>cols;
    for(int i = 0;i<N;i++){
        int x, y;
        cin>>x>>y;
        rows[x].insert(y);
        cols[y].insert(x);
    }
    ll Q;
    cin>>Q;
    while(Q--){
        int type;
        cin>>type;
        if(type == 1){
            int x;
            cin>>x;
            cout<<rows[x].size()<<endl;
            for(auto elem : rows[x]){
                cols[elem].erase(cols[elem].find(x));
            }
            rows[x].clear();
        }
        else{
            int y;
            cin>>y;
            cout<<cols[y].size()<<endl;
            for(auto elem : cols[y]){
                rows[elem].erase(rows[elem].find(y));
            }
            cols[y].clear();
        }
    }
    return 0;
}