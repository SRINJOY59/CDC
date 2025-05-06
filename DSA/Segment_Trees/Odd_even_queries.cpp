#include<bits/stdc++.h>
using namespace std;
using ll = long long;

typedef struct{
    int sum;
    int odd_cnt;
    int even_cnt;
}treenode;


void build(vector<int>&arr, vector<treenode>&t, int index, int L, int R){
    if(L == R){
        if(arr[L]&1){
            t[index].odd_cnt++;
        }
        else{
            t[index].even_cnt++;
        }
        t[index].sum = arr[L];
        return ;
    }
    int mid = (L+R)/2;
    build(arr, t, 2*index, L, mid);
    build(arr, t, 2*index+1, mid+1, R);
    t[index].sum = t[2*index].sum + t[2*index+1].sum;
    t[index].odd_cnt = t[2*index].odd_cnt + t[2*index+1].odd_cnt;
    t[index].even_cnt = t[2*index].even_cnt + t[2*index+1].even_cnt;
}

void update(vector<int>&arr, vector<treenode>&t, int index, int L, int R, int pos, int val){
    if(pos < L || pos > R) return ;
    if(L == R){
        int prev = arr[L];
        if(prev%2 == 0){
            t[index].even_cnt--;
        }
        else{
            t[index].odd_cnt--;
        }
        t[index].sum = val;
        arr[L] = val;
        if(val&1)
            t[index].odd_cnt++;
        else
            t[index].even_cnt++;
        return ;
    }
    int mid = (L+R)/2;
    update(arr, t, 2*index, L, mid, pos, val);
    update(arr, t, 2*index+1, mid+1, R, pos, val);
    t[index].sum = t[2*index].sum + t[2*index+1].sum;
    t[index].odd_cnt = t[2*index].odd_cnt + t[2*index+1].odd_cnt;
    t[index].even_cnt = t[2*index].even_cnt + t[2*index+1].even_cnt;
}

int odd_query(vector<int>&arr, vector<treenode>&t, int index, int L, int R, int LQ, int RQ){
    if(LQ > R || RQ < L) return 0;
    if(LQ <= L && R <= RQ){
        return t[index].odd_cnt;
    }
    int mid = (L+R)/2;
    return odd_query(arr, t, 2*index, L, mid, LQ, RQ) + odd_query(arr, t, 2*index+1, mid+1, R, LQ, RQ);
}

int even_query(vector<int>&arr, vector<treenode>&t, int index, int L, int R, int LQ, int RQ){
    if(LQ > R || RQ < L) return 0;
    if(LQ <= L && R <= RQ){
        return t[index].even_cnt;
    }
    int mid = (L+R)/2;
    return even_query(arr, t, 2*index, L, mid, LQ, RQ) + even_query(arr, t, 2*index+1, mid+1, R, LQ, RQ);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<treenode>t(4*n);
    build(arr, t, 1, 0, n-1);
    int Q;
    cin>>Q;
    while(Q--){
        int ch;
        cin>>ch;
        if(ch == 0){
            int x, val;
            cin>>x>>val;
            x--;
            update(arr, t, 1, 0, n-1, x, val);
        }
        else if(ch == 1){
            int LQ, RQ;
            cin>>LQ>>RQ;
            LQ--; RQ--;
            int answer = even_query(arr, t, 1, 0, n-1, LQ, RQ);
            cout<<answer<<endl;
        }
        else{
            int LQ, RQ;
            cin>>LQ>>RQ;
            LQ--; RQ--;
            int answer = odd_query(arr, t, 1, 0, n-1, LQ, RQ);
            cout<<answer<<endl;
        }
    }
    return 0;
}