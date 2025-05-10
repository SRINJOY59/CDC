#include<bits/stdc++.h>
using namespace std;

int Solution::lis(const vector<int> &arr) {
    int n = arr.size();
    vector<int>temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1;i<n;i++){
        if(arr[i] > temp.back()){
            len++;
            temp.push_back(arr[i]);
        }
        else{
            int lower = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[lower] = arr[i];
        }
    }
    return len;
}
