#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>arr(100100);
vector<int>t(400400);

void build(int index, int L, int R){
    if(L == R){
        t[index] = arr[L];
        return ;
    }
    int mid = (L + R)/2;
    build(2*index, L, mid);
    build(2*index + 1, mid+1, R);
    t[index] = t[2*index] + t[2*index+1];
}

void update(int index, int L, int R, int pos, int val){
    if(pos < L  || pos > R)
        return ;
    if(L == R){
        t[index] = val;
        arr[L] = val;
        return ;
    }
    int mid = (L + R)/2;
    update(2*index, L, mid, pos, val);
    update(2*index+1, mid+1, R, pos, val);
    t[index] = t[2*index] + t[2*index+1];
}


int query(int index, int L, int R, int LQ, int RQ){
    if(L > RQ || LQ > R){
        return 0;
    }
    //LQ <= L <= R <= RQ
    if(LQ <= L && R  <= RQ){
        return t[index];
    }
    int mid = (L+R)/2;
    return query(2*index, L, mid, LQ, RQ) + query(2*index+1, mid+1, R, LQ, RQ);
}





int main(){
    int Q;
    cin>>n>>Q;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    build(1, 0, n-1);
    while(Q--){
        int type;
        cin>>type;
        if(type == 1){
            int x, V;
            cin>>x>>V;
            update(1, 0, n-1, x-1, V);
        }
        else{
            int LQ, RQ;
            cin>>LQ>>RQ;
            int answer = query(1, 0, n-1, LQ-1, RQ-1);
            cout<<answer<<endl;
        }
    }
    return 0;
}