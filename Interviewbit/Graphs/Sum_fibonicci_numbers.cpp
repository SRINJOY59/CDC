#include<bits/stdc++.h>
using namespace std;


int Solution::fibsum(int A) {
    vector<int> fib = {1, 1};
    while (fib.back() < A) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int count = 0;
    int i = fib.size()-1;
    while(A > 0){
        if(fib[i] <= A){
            A -= fib[i];
            count++;
        }
        else{
            i--;
        }
    }
    return count;
}