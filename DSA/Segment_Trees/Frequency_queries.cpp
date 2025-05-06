#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    typedef struct {
        map<int, int> counter;
    } treenode;

    vector<treenode> t;
    int n;

    void build(vector<int>& arr, int index, int L, int R) {
        if (L == R) {
            t[index].counter[arr[L]]++;
            return;
        }
        int mid = (L + R) / 2;
        build(arr, 2 * index, L, mid);
        build(arr, 2 * index + 1, mid + 1, R);

        for (auto& p : t[2 * index].counter) {
            t[index].counter[p.first] += p.second;
        }
        for (auto& p : t[2 * index + 1].counter) {
            t[index].counter[p.first] += p.second;
        }
    }

    int query_freq(int index, int num, int L, int R, int LQ, int RQ) {
        if (RQ < L || R < LQ) return 0;
        if (LQ <= L && R <= RQ) {
            return t[index].counter[num];
        }
        int mid = (L + R) / 2;
        return query_freq(2 * index, num, L, mid, LQ, RQ) + query_freq(2 * index + 1, num, mid + 1, R, LQ, RQ);
    }

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        t.resize(4 * n);  
        build(arr, 1, 0, n - 1);
    }

    int query(int left, int right, int value) {
        return query_freq(1, value, 0, n - 1, left, right);
    }
};


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    RangeFreqQuery ds(arr);
    int Q;
    cin>>Q;
    while(Q--){
        int L, R, val;
        cin>>L>>R>>val;
        cout<<ds.query(L, R, val)<<endl;
    }
    return 0;
}