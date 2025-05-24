#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x, y;
    cin>>x>>y;
    vector<pair<int, int>>cases;
    for(int i = 1;i<=6;i++){
        for(int j = 1;j<=6;j++){
            cases.push_back({i, j});
        }
    }
    int cnt = 0;
    for(int i = 0;i<cases.size();i++){
        int a = cases[i].first;
        int b = cases[i].second;
        if(a + b >= x || abs(a - b) >= y){
            cnt++;
        }
    }
    double prob = static_cast<double>(cnt) / 36.0;
    cout << fixed << setprecision(10) << prob << endl;
    return  0;
}