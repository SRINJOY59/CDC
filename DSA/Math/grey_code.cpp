#include<bits/stdc++.h>
using namespace std;
using ll = long long;




int main(){
   ll n;
   cin>>n;
   vector<int>b(n+1, 0);
   for(ll i = n;i>=1;i--){
        cout<<b[i];
   }
   cout<<endl;
   for(int i = 1;i<(1<<n);i++){
        int lsb = __builtin_ffs(i);
        b[lsb]^=1;
        for(ll i = n;i>=1;i--){
            cout<<b[i];
        }
        cout<<endl;
   }
    return 0;
}