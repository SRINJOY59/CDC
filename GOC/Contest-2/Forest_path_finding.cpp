#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(100010);
int n;
string runes;
int maxlen = 1;

int dfs(int u, int parent){
    int first = 0;
    int second = 0;
    for(auto v: adj[u]){
        if(v == parent) continue;
        int child = dfs(v, u);
        if(runes[v] != runes[u]){
            if(child > first){
                first = child;
                second = first;
            }
            else if(child > second){
                second = child;
            }
        }
    }
    maxlen = max(maxlen, first + second);
    return first + 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        adj.clear();
        cin>>n;
        vector<int>parent(n);
        for(int i = 0;i<n;i++){
            cin>>parent[i];
            if(parent[i] != -1){
                adj[parent[i]].push_back(i);
            }
        }
        cin>>runes;
        int v = dfs(0, -1);
        cout<<maxlen<<endl;
        maxlen = 1;
    }
    return 0;
}

