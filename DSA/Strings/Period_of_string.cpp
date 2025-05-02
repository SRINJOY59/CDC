#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
vector<T> sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}



int main(){
    int T;
    cin>>T;
    for(int t = 1;t<=T;t++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<int>kmp(n+1);
        kmp[0] = -1;
        int i = 0, j = -1;
        while(i < n){
            while(j != -1 && str[i] != str[j]) j= kmp[j];
            j++;
            i++;
            kmp[i] = j;
        }
        cout<<"Test case #"<<t<<endl;
        for(int i = 2;i<=n;i++){
            if(i%(i - kmp[i]) == 0 && i/(i-kmp[i]) > 1){
                cout<<i<<" "<<i/(i - kmp[i])<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}