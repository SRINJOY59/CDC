#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<int, int>>answer;
void solve(int n, int from_tower, int to_tower, int aux_tower){
    if(n == 0) return ;
    solve(n-1, from_tower, aux_tower, to_tower);
    answer.push_back({from_tower, to_tower});
    solve(n-1, aux_tower, to_tower, from_tower);
}

int main(){
    int n;
    cin>>n;
    solve(n, 1, 3, 2);
    cout<<answer.size()<<endl;
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i].first<<" "<<answer[i].second<<endl;
    }
    return 0;
}