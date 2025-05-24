#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    cin >> S;
    int n = S.size();    
    int *digits = new int[n];
    for(int i = 0; i < n; i++){
        digits[i] = S[i] - '0';
    }    
    int current = digits[n - 1];  
    for(int i = n - 2; i >= 0; i--){
        int s = digits[i];
        if(s >= current){
            current = s;
        } else {
            int diff = current - s;
            int m = (diff + 9) / 10;
            current = s + 10 * m;
        }
    }
    
    int totalPresses = n + current;
    cout << totalPresses << "\n";
    
    delete [] digits;
    return 0;
}