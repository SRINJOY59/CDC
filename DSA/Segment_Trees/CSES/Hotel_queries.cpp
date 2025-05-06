#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int maxi;
    int max_index;
} treenode;

void build(vector<int>& arr, vector<treenode>& t, int index, int L, int R){
    if(L == R){
        t[index].maxi = arr[L];
        t[index].max_index = L;
        return;
    }
    int mid = (L + R) / 2;
    build(arr, t, 2 * index, L, mid);
    build(arr, t, 2 * index + 1, mid + 1, R);
    if(t[2*index].maxi >= t[2*index+1].maxi){
        t[index].maxi = t[2*index].maxi;
        t[index].max_index = t[2*index].max_index;
    } else {
        t[index].maxi = t[2*index+1].maxi;
        t[index].max_index = t[2*index+1].max_index;
    }
}

void update(vector<int>& arr, vector<treenode>& t, int index, int L, int R, int pos, int val){
    if(L == R){
        t[index].maxi = val;
        t[index].max_index = L;
        return;
    }
    int mid = (L + R) / 2;
    if(pos <= mid)
        update(arr, t, 2 * index, L, mid, pos, val);
    else
        update(arr, t, 2 * index + 1, mid + 1, R, pos, val);
        
    if(t[2*index].maxi >= t[2*index+1].maxi){
        t[index].maxi = t[2*index].maxi;
        t[index].max_index = t[2*index].max_index;
    } else {
        t[index].maxi = t[2*index+1].maxi;
        t[index].max_index = t[2*index+1].max_index;
    }
}

int query(vector<int>& arr, vector<treenode>& t, int index, int L, int R, int value){
    if(t[index].maxi < value)
        return -1;

    if(L == R)
        return L;

    int mid = (L + R) / 2;
    if(t[2 * index].maxi >= value)
        return query(arr, t, 2 * index, L, mid, value);
    else
        return query(arr, t, 2 * index + 1, mid + 1, R, value);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<treenode> t(4 * n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    build(arr, t, 1, 0, n - 1);

    while(m--){
        int value;
        cin >> value;
        int idx = query(arr, t, 1, 0, n - 1, value);
        if(idx == -1)
            cout << 0 << " ";
        else {
            cout << idx + 1 << " ";
            arr[idx] -= value;
            update(arr, t, 1, 0, n - 1, idx, arr[idx]);
        }
    }
    cout << endl;
    return 0;
}
